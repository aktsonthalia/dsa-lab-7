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
	Employee temp1, temp2, temp3;
	Employee pivot = list[end];
	int pivot_key = getEmpID(pivot);
	int i = start, k = end;
	int current_key;

	for(int j=start; j<end; j++)
	{
		current_key = getEmpID(list[j]);
		if(current_key > pivot_key)
			continue;

		temp1 = list[j];
		temp3 = list[i];

		for(int k=i; k<j; k++)
		{	
			temp2 = list[k+1];
			list[k+1] = temp3;
			temp3 = temp2;
		}

		list[i++] = temp1;
	}	

	temp1 = list[i];
	list[i] = pivot;
	list[end] = temp1;
	return i;

}