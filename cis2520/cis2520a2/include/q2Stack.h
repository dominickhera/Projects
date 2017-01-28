#ifndef __DHERA_STACK__
#define __DHERA_STACK__


/*
defines stack, pop and push fucntions.
*/

typedef struct Stack 
{
    float info;
    struct Stack * next;

}Stack;

void push(Stack ** top, float input);
float pop(Stack** top);

#endif 