#include "employee.h"
#include "quicksort.h"
#include "stack.h"

void sort_q(Employee list[], int N, int S)
{
	Stack boundaries = createStack();
	int start = 0;
	int end = N-1;
	push(boundaries, end);
	push(boundaries, start);
	int pivot;

	while(isEmpty(boundaries) == 0)
	{
		start = pop(boundaries);
		end = pop(boundaries);

		pivot = partition(list, start, end);

		if(pivot - start > S)
		{
			push(boundaries, pivot-1);
			push(boundaries, start);
		}

		if(end - pivot > S)
		{
			push(boundaries, end);
			push(boundaries, pivot+1);
		}
	}
}

int partition(Employee list[], int start, int end)
{
	Employee temp;
	int pivot_index = (start + end) / 2;
	Employee pivot = list[pivot_index];
	int pivot_key = getEmpID(pivot);
	int i = start-1, k = end;
	int current_key;

	for(int j=start; j<end; j++)
	{
		current_key = getEmpID(list[j]);

		if(current_key <= pivot_key)
		{
			i++;
			temp = list[j];
			list[j] = list[i];
			list[i] = temp;
		}
	}

	temp = list[i+1];
	list[i+1] = list[pivot_index];
	list[pivot_index] = temp;
	
	return i+1;

}