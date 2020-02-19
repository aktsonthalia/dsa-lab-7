#include "employee.h"
#include "insertionsort.h"
#include "quicksort.h"

void mixedsort(Employee list[], int N, int S)
{
	sort_q(list, N, S);
	sort_i(list, N);
}