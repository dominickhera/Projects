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

// void push(float input, stack * newTop)
// {
// 	stack * newTop = malloc(sizeof(newTop));
// 	newTop->next = newTop;
// 	newTop->info = input;
// }

// int pop(stack *stack)
// {
//     int x;
//     x=stack->info[stack->next];
//     stack->next = stack->next-1;
// }
// #include <stdio.h>
 
// #define MAX 20
 
// typedef struct stack
// {
//     int data[MAX];
//     int top;
// }stack;
 
// void init(stack *);
// int empty(stack *);
// int full(stack *);
// int pop(stack *);
// void push(stack *,int);
// int evaluate(char x,int op1,int op2);
 
// int main()
// {
//     stack s;
//     char x;
//     int op1,op2,val;
//     init(&s);
//     printf("Enter the expression(eg: 59+3*)\nSingle digit operand and operators only:");
    
//     while((x=getchar())!='\n')
//     {
//         if(isdigit(x))
//             push(&s,x-48);        //x-48 for removing the effect of ASCII
//         else
//         {
//             op2=pop(&s);
//             op1=pop(&s);
//             val=evaluate(x,op1,op2);
//             push(&s,val);
//         }
//     }
    
//     val=pop(&s);
//     printf("\nValue of expression=%d\n",val);
 
//     return 0;
// }
 
// int evaluate(char x,int op1,int op2)
// {
//     if(x=='+')
//         return(op1+op2);
//     if(x=='-')
//         return(op1-op2);
//     if(x=='*')
//         return(op1*op2);
//     if(x=='/')
//         return(op1/op2);
//     if(x=='%')
//         return(op1%op2);
// }
 
// void init(stack *s)
// {
//     s->top=-1;
// }
 
// int empty(stack *s)
// {
//     if(s->top==-1)
//         return(1);
    
//     return(0);
// }
 
// int full(stack *s)
// {
//     if(s->top==MAX-1)
//         return(1);
    
//     return(0);
// }
 
// void push(stack *s,int x)
// {
//     s->top=s->top+1;
//     s->data[s->top]=x;
// }
 
// int pop(stack *s)
// {
//     int x;
//     x=s->data[s->top];
//     s->top=s->top-1;
// } 
   