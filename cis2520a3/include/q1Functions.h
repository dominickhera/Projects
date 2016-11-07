#ifndef __DHERA_FUNCTIONS__
#define __DHERA_FUNCTIONS__

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum TYPE
{
    OPERATOR,
    VARIABLE,
    VALUE,
    DEFAULT
};

typedef struct treeNode
{
    struct treeNode * leftBranch;
    struct treeNode * rightBranch;
    float num;
    char operator;
    char nodeID;
    enum TYPE type;

}treeNode;

int operatorCheck(char operatorThing);
treeNode * createHead();
treeNode * parseExpression(char * expression);
void preorderFunction(treeNode *temp);
void inorderFunction(treeNode *temp);
void searchInorderFunction( treeNode *temp, char tempVal, float tempValue);
void postorderFunction(treeNode *temp);
void updateFunction(treeNode * start);
float checkExpression(treeNode * temp);


#endif 