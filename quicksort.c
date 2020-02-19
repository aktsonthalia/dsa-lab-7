#include "employee.h"
#include "quicksort.h"

extern void sort_q(Employee list[], int N, int S)
{
	int length;
	int num_segments;

	if(S < 1)
		S = 1;

	for(length = S; length <= N; length++)
	{
		num_segments = N / length;
		for(int i=0; i<num_segments; i++)
			step(list, i*length, (i+1)*length-1);
	}
}

extern void step(Employee list[], int start, int end)
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

}