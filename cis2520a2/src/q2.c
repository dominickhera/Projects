#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "q2Stack.h"


/*

main function:
parses the command line arguement to see 
if they are a digit or a basic sign (+/-/x//)
then pushes number to stack if it's a number
or pops off the stack if its a symbol and does
the following math and then goes through
the entire line repeating itself.

*/

int main(int argc, char* argv[])
{

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