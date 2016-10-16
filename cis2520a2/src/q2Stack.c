#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "q2Stack.h"

void push(Stack ** top, float input)
{
	Stack * new = malloc(sizeof(Stack));
	if (!new) exit(-1);
	new->info = input;
	new->next = *top; 
	*top = new; 
	printf("=");
}

float pop(Stack** top)
{
	float tempData = 0.0;

	Stack* temp;

	if(temp == NULL)
	{
		printf("nothing is on the stack.\n");
		return 0.0;
	}

	temp = *top;
	*top = temp->next;
	tempData = temp->info;
	free(temp);

	return tempData;
}