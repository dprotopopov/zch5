#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> 
#include <mpi.h> 

#ifndef max
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

#define DATA_TAG 1

int main(int argc, char *argv[])
{
	int nrank;     /* Общее количество процессов */
	int myrank;    /* Номер текущего процесса */
	MPI_Status status;

	/* Иницилизация MPI */
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &nrank);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

	if (myrank == 0 && argc < 3){
		printf("Usage :\t%s <inputfile> <outputfile>\n", argv[0]); fflush(stdout);
	}

	if (argc < 3){
		MPI_Finalize();
		exit(-1);
	}

	int count;
	double v;
	double *vi;
	double *upperi;
	double *loweri;
	char *inputFileName;
	char *outputFileName;
	int i, j;

	// Получаем параметры - имена файлов
	inputFileName = argv[1];
	outputFileName = argv[2];

	if (myrank == 0) {

		printf("Input file name :\t%s\n", inputFileName);
		printf("Output file name :\t%s\n", outputFileName);

		/* Заполняем массив числами */
		/* Операция выполняется только на ведущем процессе */
		FILE *fl = fopen(inputFileName, "r");
		fscanf(fl, "%d", &count);
		fscanf(fl, "%e", &v);
		vi = static_cast<double *>(malloc(count*sizeof(double)));
		for (i = 0; i<count; i++) {
			fscanf(fl, "%e", &vi[i]);
		}
		fclose(fl);
	}

	if (nrank > 1) MPI_Bcast(&count, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (nrank > 1) MPI_Bcast(&v, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	if (myrank > 0) vi = static_cast<double *>(malloc(count*sizeof(double)));
	if (nrank > 1) MPI_Bcast(vi, count, MPI_DOUBLE, 0, MPI_COMM_WORLD);

	upperi = static_cast<double *>(malloc(count*sizeof(double)));
	loweri = static_cast<double *>(malloc(count*sizeof(double)));

	for (i = 0; i < count; i++) upperi[i] = v;
	for (i = 0; i < count; i++) loweri[i] = 1.0/v;

	free(vi);
	free(upperi);
	free(loweri);

	MPI_Finalize();
	exit(0);
}
