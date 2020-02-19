#include "employee.h"
#include "insertionsort.h"
#include "quicksort.h"

extern double tolerance;

typedef struct runningtimes * runningtimes;
void printRunningTimes(runningtimes r);
runningtimes testRun(Employee list[], int size);
int estimateCutoff(FILE* f, int size);