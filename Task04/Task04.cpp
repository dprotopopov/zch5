#define _CRT_SECURE_NO_WARNINGS

// Task04.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <float.h>
#include <vector>
#include <numeric>
#include <fstream>
#include <mpi.h> 

#define DATA_TAG 1

// искомая функция
double func(int count, std::vector<int>& vi, int v, std::vector<int>& ui)
{
	double y = 0.0;
	for (int i = 0; i < count; i++)
	{
		if (ui[i] == 0) return DBL_MAX ;
		double z = static_cast<double>(vi[i]) / v - static_cast<double>(vi[i]) / ui[i];
		y += z * z;
	}
	return y;
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

	int count;
	int v;
	double y;
	std::vector<int> vi;
	std::vector<int> ui;
	char* inputFileName;
	char* outputFileName;

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

	// Получаем параметры - имена файлов
	inputFileName = argv[1];
	outputFileName = argv[2];

	/* Заполняем массив числами */
	if (myrank == 0)
	{
		std::ifstream ifs(inputFileName, std::ifstream::in);
		ifs >> count;
		ifs >> v;
		for (int i = 0; i < count; i++)
		{
			int x;
			ifs >> x;
			vi.push_back(x);
		}
		ifs.close();
	}

	if (nrank > 1) MPI_Bcast(&count, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (nrank > 1) MPI_Bcast(&v, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (myrank > 0) vi.resize(count);
	if (nrank > 1) MPI_Bcast(&vi[0], count, MPI_INT, 0, MPI_COMM_WORLD);

	ui.push_back(v);
	for (int i = 1; i < count; i++) ui.push_back(0);
	y = func(count, vi, v, ui);
	std::vector<int> xi(count);
	std::copy(ui.begin(), ui.end(), xi.begin());
	
	for (int j = 0;;j%=nrank)
	{
		xi[xi.size() - 1]--;
		if (xi[xi.size() - 1] == -1)
		{
			xi.pop_back();
			if (xi.size() == 0) break;
			continue;
		}

		for (int i = xi.size(); i < count; i++)
			xi.push_back(v - std::accumulate(xi.begin(), xi.end(), 0));

		if (j++%nrank != myrank) continue;

		double y1 = func(count, vi, v, xi);
		if (y1 < y)
		{
			y = y1;
			std::copy(xi.begin(), xi.end(), ui.begin());
		}
	}
	if (myrank > 0)
	{
		MPI_Send(&y, 1, MPI_DOUBLE, 0, DATA_TAG, MPI_COMM_WORLD);
		MPI_Send(&ui[0], count, MPI_INT, 0, DATA_TAG, MPI_COMM_WORLD);
	}

	xi.resize(count);
	for (int i = 1; i < nrank;i++)
	{
		double y1;
		MPI_Recv(&y1, 1, MPI_DOUBLE, i, DATA_TAG, MPI_COMM_WORLD, &status);
		MPI_Recv(&xi[0], count, MPI_INT, i, DATA_TAG, MPI_COMM_WORLD, &status);
		if (y1<y)
		{
			y = y1;
			std::copy(xi.begin(), xi.end(), ui.begin());
		}
	}

	if (myrank == 0)
	{
		std::ofstream ofs(outputFileName, std::ofstream::out);
		for (int i = 0; i < count; i++)
		{
			ofs << ui[i] << '\n';
		}
		ofs.close();
	}
	return 0;
}
