#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "q2Stack.h"


/*
takes the input value onto the top of the stack 
and pushes the previous top of the sack
down below it
*/ 

void push(Stack ** top, float input)
{
	Stack * new = malloc(sizeof(Stack));
	if (!new) exit(-1);
	new->info = input;
	new->next = *top; 
	*top = new; 
	printf("=");
}


/*
takes the top of the stack and removes it,
pushing the value below it to the top 
of the stack and then frees the stack.
*/

float pop(Stack** top)
{
	float tempData = 0.0;

	Stack* temp = NULL;

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