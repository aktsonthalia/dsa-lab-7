#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"

int name_len = 10;


typedef struct Employee
{
	char* name;
	int empID;
} * Employee;

Employee createEmployee(char name[], int empID)
{
	Employee employee = malloc(sizeof(Employee));
	employee -> name = malloc((name_len+1) * sizeof(char));
	strcpy(employee -> name, name);
	employee -> empID = empID;
	return employee;
}	

int getEmpID(Employee employee)
{
	return employee -> empID;
}

void printEmployee(Employee employee)
{
	printf("Name: %s, ID: %d\n", employee -> name, employee -> empID);
}

void printEmployeeList(Employee list[], int N)
{
	for(int i=0; i<N; i++)
	{
		printf("%d. ", i+1);
		printEmployee(list[i]);
	}
}

void readFromFile(FILE* f, Employee list[], int N)
{
	// printf("readFromFile working\n");
	char name[name_len];
	int empID;
	int i=0;
	// printf("%d\n", list==NULL);
	while(i<N)
	{
		fscanf(f, "%s %d\n", name, &empID);
		list[i++] = createEmployee(name, empID);
		// printf("readFromFile %d\n", i);
	}
	rewind(f);
}



void shallowCopy(Employee dest[], Employee src[], int N)
{
	for(int i=0; i<N; i++)
		dest[i] = src[i];
}

void fprintEmployee(FILE* f, Employee employee)
{
	fprintf(f, "Name: %s, ID: %d\n", employee -> name, employee -> empID);	
}

void fprintEmployeeList(FILE* f, Employee list[], int N)
{
	for(int i=0; i<N; i++)
	{
		fprintf(f, "%d. ", i+1);
		fprintEmployee(f, list[i]);
	}
}
