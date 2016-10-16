#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "q2Stack.h"

/*typedef struct Stack 
{
    float info;
    struct Stack * next;

}Stack;

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
}*/

int main(int argc, char* argv[])
{
	// struct mainStruct * stack;
	Stack * stack; 


	if(argc != 1)
	{
		for(int i = 1; i < argc; i++)
		{

			for(int j = 0; j < strlen(argv[i]); j++)
			{

				if(isdigit(argv[i][j]))
				{
					char tempNum = argv[i][j];
					push(&stack, atof(&tempNum));
				}
				else
				{
					if(argv[i][j] == '+')
					{
						float num1 = pop(&stack); 
						float num2 = pop(&stack);
						float answer = num1 + num2;

						push(&stack, answer);

					}
					else if(argv[i][j] == '-')
					{
						float num1 = pop(&stack);
						float num2 = pop(&stack);
						float answer = num2 - num1;

						push(&stack, answer);
					}
					else if(argv[i][j] == '*')
					{
						float num1 = pop(&stack);
						float num2 = pop(&stack);
						float answer = num1 * num2;

						push(&stack, answer);
					}
					else if(argv[i][j] == '/')
					{
						float num1 = pop(&stack);
						float num2 = pop(&stack);
						float answer = num1 / num2;

						push(&stack, answer);
					}

				}
			}
		}
	}	
	else
	{
		printf("please enter proper amount of command line arguements\n");
		exit(1);
	}

	printf("\nAnswer: %.2lf\n", stack->info);

	return 0;
}