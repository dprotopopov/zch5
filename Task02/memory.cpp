#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <float.h>
#include <string.h>
#include <mpi.h> 

#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

#define DATA_TAG 1

// искомая функция
double func(int count, double* vi, double* ui)
{
	double y = 0.0;
	for (int i = 0; i < count; i++)
	{
		if (ui[i] < 0.001) return DBL_MAX ;
		y += vi[i] / ui[i];
	}
	return y;
}

// функция проверки ограничений
bool check(int count, double* ui, double v)
{
	double y = 0.0;
	for (int i = 0; i < count; i++)
	{
		y += ui[i];
	}
	return y <= v;
}

int main(int argc, char* argv[])
{
	int nrank; /* Общее количество процессов */
	int myrank; /* Номер текущего процесса */
	MPI_Status status;

	/* Иницилизация MPI */
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nrank);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

	if (myrank == 0 && argc < 3)
	{
		printf("Usage :\t%s <inputfile> <outputfile>\n", argv[0]);
		fflush(stdout);
	}

	if (argc < 3)
	{
		MPI_Finalize();
		exit(-1);
	}

	int count;
	double v, y;
	double* vi = NULL;
	double* ui; // лучшее значение
	double* xi; // перебираемое значение
	double* upperi; // верхняя границы
	double* loweri; // нижняя граница
	char* inputFileName;
	char* outputFileName;

	// Получаем параметры - имена файлов
	inputFileName = argv[1];
	outputFileName = argv[2];

	if (myrank == 0)
	{
		printf("Input file name :\t%s\n", inputFileName);
		printf("Output file name :\t%s\n", outputFileName);

		/* Заполняем массив числами */
		/* Операция выполняется только на ведущем процессе */
		FILE* fl = fopen(inputFileName, "r");
		fscanf(fl, "%d", &count);
		fscanf(fl, "%lf", &v);
		printf("v = %lf\n", v);
		vi = static_cast<double *>(malloc(count * sizeof(double)));
		for (int i = 0; i < count; i++)
		{
			fscanf(fl, "%lf", &vi[i]);
			printf("vi[%d] = %lf\n", i, vi[i]);
		}
		fclose(fl);
	}

	if (nrank > 1) MPI_Bcast(&count, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (nrank > 1) MPI_Bcast(&v, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	if (myrank > 0) vi = static_cast<double *>(malloc(count * sizeof(double)));
	if (nrank > 1) MPI_Bcast(vi, count, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	y = DBL_MAX ;
	ui = static_cast<double *>(malloc(count * sizeof(double)));
	xi = static_cast<double *>(malloc(count * sizeof(double)));
	upperi = static_cast<double *>(malloc(count * sizeof(double)));
	loweri = static_cast<double *>(malloc(count * sizeof(double)));

	for (int i = 0; i < count; i++) upperi[i] = v * 2 / count;
	for (int i = 0; i < count; i++) loweri[i] = 0.0;
	for (int i = 0; i < count; i++) ui[i] = 0.0;

	long total = 1L << (2 * count); // количество перебираемых точек


	for (;;)
	{
		double distance = 0.0;
		for (int i = 0; i < count; i++) distance = max(distance, upperi[i] - loweri[i]);
		if (distance < 0.001) break;

		for (long index = myrank * total / nrank; index < (myrank + 1) * total / nrank; index++)
		{
			long index2 = index;
			for (int i = 0; i < count; i++)
			{
				int j = index2 & 3;
				index2 >>= 2;
				xi[i] = loweri[i] + (upperi[i] - loweri[i]) * j / 3;
			}
			if (!check(count, xi, v)) continue;
			double y2 = func(count, vi, xi);
			if (y2 < y)
			{
				y = y2;
				memcpy(ui, xi, count * sizeof(double));
			}
		}
		if (myrank == 0)
		{
			for (int i = 1; i < nrank; i++)
			{
				double y2;
				MPI_Recv(&y2, 1, MPI_DOUBLE, i, DATA_TAG, MPI_COMM_WORLD, &status);
				MPI_Recv(xi, count, MPI_DOUBLE, i, DATA_TAG, MPI_COMM_WORLD, &status);
				if (y2 < y)
				{
					y = y2;
					memcpy(ui, xi, count * sizeof(double));
				}
			}
			for (int i = 0; i < count; i++) loweri[i] = max(0.0, ui[i] - (upperi[i] - loweri[i]) / 3);
			for (int i = 0; i < count; i++) upperi[i] = min(v, ui[i] + (upperi[i] - loweri[i]) / 3);
		}
		if (myrank > 0)
		{
			MPI_Send(&y, 1, MPI_DOUBLE, 0, DATA_TAG, MPI_COMM_WORLD);
			MPI_Send(ui, count, MPI_DOUBLE, 0, DATA_TAG, MPI_COMM_WORLD);
		}
		MPI_Bcast(loweri, count, MPI_DOUBLE, 0, MPI_COMM_WORLD);
		MPI_Bcast(upperi, count, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	}

	/* выводим результаты */
	if (myrank == 0)
	{
		FILE* fl = fopen(outputFileName, "w");
		for (int i = 0; i < count; i++)
		{
			fprintf(fl, "%lf\n", ui[i]);
			printf("ui[%d] = %lf\n", i, ui[i]);
		}
		fclose(fl);
	}

	free(vi);
	free(xi);
	free(ui);
	free(upperi);
	free(loweri);

	MPI_Finalize();
	exit(0);
}
