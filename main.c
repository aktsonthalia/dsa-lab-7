#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "employee.h"
#include "estimatecutoff.h"
#include "quicksort.h"
#include "insertionsort.h"
#include "mixedsort.h"
#include "stack.h"

#define MAX 20000
#define a 1
#define b 6
#define TIME_DATA "Running_times.txt"

void main(int argc, char* argv[])
{
	// int n = 1000000000;
	FILE* inputfile = fopen(argv[1], "r");
	FILE* outputfile;
	FILE* tf = fopen(TIME_DATA, "w");
	fclose(tf);

	struct timeval t1, t2;
	double elapsedTime;
	char out[20];

	//Estimating cutoff
	Employee list[MAX];
	readFromFile(inputfile, list, MAX);

	printf("Estimating cutoff, please wait...\n");
	int cutoff = estimateCutoff(inputfile, MAX);
	printf("Cutoff: %d\n", cutoff);

	printf("Running times can be found in the file %s\n", TIME_DATA);

	for(int N = pow(10, a); N <= pow(10, b); N *= 10)
	{
		tf = fopen(TIME_DATA, "a");
		Employee list2[N];
		printf("Running on N = %d.\n", N);
		readFromFile(inputfile, list2, N);

		//calculating execution time for the sorting algorithm
		gettimeofday(&t1, NULL);
		sort_q(list2, N, cutoff);
		gettimeofday(&t2, NULL);
		
		elapsedTime = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1000000.0;

		printf("Done. Please find the output in %d.out\n", N);
		sprintf(out, "%d.out", N);
		outputfile = fopen(out, "w");
		fprintEmployeeList(outputfile, list2, N);
		fclose(outputfile);

		fprintf(tf, "N = %d, Hybrid sort took %f seconds.\n", N, elapsedTime);
		fclose(tf);
	}

	fclose(inputfile);
}