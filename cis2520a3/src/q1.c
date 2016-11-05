#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

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


int operatorCheck(char operator)
{
    if (operator == '*' || operator == '/' || operator == '-' || operator == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

treeNode * createHead()
{
	treeNode * new = malloc(sizeof(treeNode));
	new->rightBranch = NULL;
	new->leftBranch = NULL;

	return new;
}

treeNode * parseExpression(char * expression)
{
    // char expressionInput[256];
    int bracketCount = 0;
    // int subCount = 0;
    // int otherSubCount = 0;
    int newSplit = 0;
    int length = strlen(expression) - 1;
    int actualLength = strlen(expression);

    // printf("%s is %d chracters long\n", expression, length);

    for (int i = 0; i < length; i++)
    {

        if(expression[i] == '(')
        {
            bracketCount++;
        }

        if(expression[i] == ')')
        {
            bracketCount--;
        }

        if(bracketCount == 1 && operatorCheck(expression[i]) == 1 )
        {
            newSplit = i;

            char * leftBranch = malloc(sizeof(char)*256);
            memset(leftBranch, '\0', 256);
            char * rightBranch = malloc(sizeof(char)*256);
            memset(rightBranch, '\0', 256);

            strncpy(leftBranch, &expression[1], newSplit - 1);
            strncpy(rightBranch, &expression[newSplit + 1], (actualLength - 2) - newSplit);

            treeNode * new = createHead();
            // while(subCount <= length)
            // {
            // 	strcpy(&expressionInput[otherSubCount], &expression[subCount]);
            // 	subCount++;
            // 	otherSubCount++;
            // }
            // break;
        }
    }

}

int main(int argc, char* argv[])
{
    // int userInput = 0;
    char * expression = argv[1];
    treeNode * start = parseExpression(expression);


    // printf("%s\n", expressionInput);

    // while (userInput != 7)
    // {

    // 	printf("(1) Display\n(2) Preorder\n(3) Inorder\n(4) Postorder\n(5) Update\n(6) Calclulate\n(7) Exit\n");
    // 	scanf("%d", &userInput);

    // 	switch(userInput)
    // 	{
    // 		case 1:
    // 			// printf("enter expression input:\n");
    // 			// scanf("%s", expressionInput);
    // 			// printf("%s is your input\n", expressionInput);
    // 			break;
    // 		case 2:
    // 			printf("2\n");
    // 			break;
    // 		case 3:
    // 			printf("3\n");
    // 			break;
    // 		case 4:
    // 			printf("4\n");
    // 			break;
    // 		case 5:
    // 			printf("5\n");
    // 			break;
    // 		case 6:
    // 			printf("6\n");
    // 			break;
    // 		case 7:
    // 			printf("goodbye\n");
    // 			exit(1);
    // 		default:
    // 			printf("please enter a number between 1 and 7\n");
    // 	}
    // }

    return 0;
}
