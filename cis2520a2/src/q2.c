#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include "q2Stack.h"

struct stack 
{
    float info;
    struct stack * next;
};

typedef struct stack stack;


void push(float input)
{
	stack * newTop = malloc(sizeof(newTop));
	newTop->next = newTop;
	newTop->info = input;

	printf("pushed into stack\n");
}

int pop(stack)
{

}

int main(int argc, char* argv[])
{

	if(argc != 1)
	{
		for(int i = 1; i < argc; i++)
		{

			for(int j = 0; j < strlen(argv[i]); j++)
			{

				if(isdigit(argv[i][j]))
				{
					printf("%c is a number\n", argv[i][j]);
					push(atof(&argv[i][j]));
				}
				else
				{
					if(argv[i][j] == '+')
					{
						printf("%c is a addition sign\n", argv[i][j]);
					}
					else if(argv[i][j] == '-')
					{
						printf("%c is a subtraction sign\n", argv[i][j]);
					}
					else if(argv[i][j] == '*')
					{
						printf("%c is a multiplication sign\n", argv[i][j]);
					}
					else if(argv[i][j] == '/')
					{
						printf("%c is a division sign\n", argv[i][j]);
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

	return 0;

}