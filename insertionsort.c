#include "employee.h"
#include "insertionsort.h"


void sort_i(Employee list[], int N)
{	
	Employee temp;
	int key1, key2;

	for(int i=1; i<N; i++)
	{
		for(int j=i-1; j>=0; j--)
		{			
			key1 = getEmpID(list[j]);
			key2 = getEmpID(list[j+1]);

			if(key1 <= key2)
				break;

			temp = list[j];
			list[j] = list[j+1];
			list[j+1] = temp;
		}
	}
}