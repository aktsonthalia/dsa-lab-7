#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct Node
{
	int element;
	Node next;
} * Node;

typedef struct Stack 
{	
	Node top;
	int count;
} * Stack;

Stack createStack()
{
	Stack stack = malloc(sizeof(Stack));
	stack -> top = NULL;
	stack -> count = 0;
	return stack;
}

void push(Stack s, int n)
{
	Node new = malloc(sizeof(Node));
	new -> element = n;

	Node temp = s -> top;
	s -> top = new;
	new -> next = temp;
	s -> count++;
	// printStack(s);
}

int pop(Stack s)
{	
	if(isEmpty(s))
		return -1;
	Node temp = s -> top;
	int element = temp -> element;
	s -> top = temp -> next;
	free(temp);
	s -> count--;
	return element;
}

void printStack(Stack s)
{
	Node current = s -> top;
	while(current != NULL)
	{
		printf("%d ", current -> element);
		current = current -> next;
	}
	printf("\n");
}

int isEmpty(Stack s)
{
	return (s->count == 0) ? 1 : 0;
}