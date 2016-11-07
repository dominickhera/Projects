#ifndef __DHERA_FUNCTIONS__
#define __DHERA_FUNCTIONS__

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//used enum to figure out difference between types of input
enum TYPE
{
    OPERATOR,
    VARIABLE,
    VALUE,
    DEFAULT
};


//struct used for tree
typedef struct treeNode
{
    struct treeNode * leftBranch;
    struct treeNode * rightBranch;
    float num;
    char operator;
    char nodeID;
    enum TYPE type;

}treeNode;

//checks if the character is an operator and returns 1 if it is
int operatorCheck(char operatorThing);
//creates a new head for the tree
treeNode * createHead();
//parses the current function storing the pieces into the tree and recursively calling itself until all pieces are stored
treeNode * parseExpression(char * expression);
//changes the tree into preorder - order 
void preorderFunction(treeNode *temp);
//changes tree into inodrer - order
void inorderFunction(treeNode *temp);
//searches through both side of the tree for a value and replaces it with the inputed value
void searchInorderFunction( treeNode *temp, char tempVal, float tempValue);
//changes tree into postorder -order
void postorderFunction(treeNode *temp);
//finds value to be replaced and updates it with the new value
void updateFunction(treeNode * start);
//checks expression to see what operator is found and returns the proper value.
float checkExpression(treeNode * temp);


#endif 