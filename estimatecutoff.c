#include <math.h>
#include <stdbool.h>
#include <sys/time.h>

#include "employee.h"
#include "estimatecutoff.h"
#include "insertionsort.h"
#include "quicksort.h"


double tolerance = 0.00005;

typedef struct runningtimes
{
	double time_i;
	double time_q;
	int size;
} * runningtimes;

runningtimes testRun(Employee list[], int size)
{
	double time_i = 0.0;
	double time_q = 0.0;
	struct timeval t1, t2, t3, t4;

	Employee list1[size];
	Employee list2[size];
	shallowCopy(list1, list, size);
	shallowCopy(list2, list, size);

	gettimeofday(&t1, NULL);
	sort_i(list2, size);
	gettimeofday(&t2, NULL);

	time_i = t2.tv_sec - t1.tv_sec;
	time_i += (t2.tv_usec - t1.tv_usec) / 1000000.0;

	gettimeofday(&t1, NULL);
	sort_q(list1, size, 0);
	gettimeofday(&t2, NULL);

	time_q = t2.tv_sec - t1.tv_sec;
	time_q += (t2.tv_usec - t1.tv_usec) / 1000000.0;

	runningtimes r = malloc(sizeof(runningtimes));
	r -> time_i = time_i;
	r -> time_q = time_q;
	r -> size = size;

// 
	return r;
}

void printRunningTimes(runningtimes r)
{
	printf("N = %d.\n", r -> size);
	printf("Insertion sort took: %f s.\n", r -> time_i);
	printf("Quicksort took: %f s.\n", r -> time_q);	
}

int estimateCutoff(FILE* f, int size)
{
	int min = 1, max = size;
	
	Employee list1[min];
	readFromFile(f, list1, min);
	Employee list2[max];
	readFromFile(f, list2, max);
	runningtimes r1 = testRun(list1, min);
	runningtimes r2 = testRun(list2, max);

	// printRunningTimes(r1);
	// printRunningTimes(r2);
	double diff;
	while(true)
	{
		int mid = (min + max) / 2;
		Employee list3[mid];
		readFromFile(f, list3, mid);
		runningtimes r = testRun(list3, mid);
		// printRunningTimes(r);

		diff = r -> time_i - r -> time_q;
		// printf("%f\n", fabs(diff));

		if(fabs(diff) < tolerance)
			return mid;


		if(diff > 0)
			max = mid;
		else
			min = mid;
	}


}