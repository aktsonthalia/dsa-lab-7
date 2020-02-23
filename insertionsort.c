#include "employee.h"
#include "insertionsort.h"


void sort_i(Employee list[], int N)
{	
	Employee key;
	int keyID;
	int key1, key2;
	int i, j;

	for(i=1; i<N; i++)
	{
		key = list[i];
		keyID = getEmpID(key);
		j = i-1;

		while(j > 0 && getEmpID(list[j]) > keyID)
		{	
			list[j+1] = list[j];
			j--;
		}

		list[j+1] = key;
	}
}