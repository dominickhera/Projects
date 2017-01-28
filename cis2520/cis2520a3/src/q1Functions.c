#include "q1Functions.h"

int operatorCheck(char operatorThing)
{

    if (operatorThing == '*' || operatorThing == '/' || operatorThing == '-' || operatorThing == '+')
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

    int bracketCount = 0;
    int rightBranchCount = 0;
    int leftBranchCount = 0;
    int newSplit = 0;
    int length = strlen(expression) - 1;
    int actualLength = strlen(expression);

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
            new->type = OPERATOR;
            new->operator = expression[newSplit];


            for (int j = 0;j< strlen(leftBranch); j++)
            {
                if(operatorCheck(leftBranch[j]) == 1)
                {
                    leftBranchCount++;
                }
            }

            for (int j = 0; j < strlen(rightBranch); j++)
            {
                if(operatorCheck(rightBranch[j] == 1))
                {
                    rightBranchCount++;
                }
            }

            if (leftBranchCount == 0 && rightBranchCount == 0)
            {
                treeNode * rightReplace = createHead();

                if(isalpha(rightBranch[0]))
                {
                    rightReplace->nodeID = rightBranch[0];
                    rightReplace->type =  VARIABLE;
                    char * rightTemp = malloc(sizeof(char)*strlen(rightTemp) - 1);
                    memset(rightTemp, '\0', strlen(rightBranch) - 1);
                    strcpy(rightTemp, &rightBranch[1]);
                    rightReplace->num = atof(rightTemp);
                    new->rightBranch = rightReplace;
                }
                else
                {
                    rightReplace->num = atof(rightBranch);
                    rightReplace->type = VALUE;
                    new->rightBranch = rightReplace;
                }

                treeNode * leftReplace = createHead();

                if(isalpha(leftBranch[0]))
                {
                    leftReplace->nodeID = leftBranch[0];
                    leftReplace->type = VARIABLE;
                    char * leftTemp = malloc(sizeof(char)*strlen(leftBranch)-1);
                    memset(leftTemp, '\0', strlen(leftBranch) - 1);
                    strcpy(leftTemp, &leftBranch[1]);
                    leftReplace->num = atof(leftTemp);
                    new->leftBranch = leftReplace;
                }
                else
                {
                    leftReplace->type = VALUE;
                    leftReplace->num = atof(leftBranch);
                    new->leftBranch = leftReplace;
                }

                return new;
            }

            else if(rightBranchCount == 0)
            {
                treeNode * rightReplace = createHead();

                if(isalpha(rightBranch[0]))
                {
                    rightReplace->nodeID = rightBranch[0];
                    rightReplace->type = VARIABLE;
                    char * rightTemp = malloc(sizeof(char)*strlen(rightBranch)-1);
                    memset(rightTemp, '\0', strlen(rightBranch)-1);
                    strcpy(rightTemp, &rightBranch[1]);
                    rightReplace->num = atof(rightTemp);
                    new->rightBranch = rightReplace;
                }
                else
                {

                    rightReplace->num = atof(rightBranch);
                    rightReplace->type = VALUE;
                    new->rightBranch = rightReplace;

                }

                new->leftBranch = parseExpression(leftBranch);
                return new;
            }

            else if(leftBranchCount == 0)

            {
                treeNode * leftReplace = createHead();
                if(isalpha(leftBranch[0]))
                {
                    leftReplace->nodeID = leftBranch[0];
                    leftReplace->type = VARIABLE;
                    new->leftBranch = leftReplace;
                }
                else
                {
                    leftReplace->num = atof(leftBranch);
                    leftReplace->type = VALUE;
                    new->leftBranch = leftReplace;
                }

                new->rightBranch = parseExpression(rightBranch);

                return new;
            }
            else
            {
                new->leftBranch = parseExpression(leftBranch);
                new->rightBranch = parseExpression(rightBranch);

                return new;
            }
        }
    }
    return NULL;
}

void preorderFunction(treeNode *temp)
{
    if(temp)
    {
        switch(temp->type)
        {
            case OPERATOR:
                printf("%c ", temp->operator);
                break;
            case VARIABLE:
                printf("%c%.2f ", temp->nodeID, temp->num);
                break;
            case VALUE:
                printf("%.2f ", temp->num);
                break;
                // case OPERATOR:
                // 	printf("%c ", temp->operator);
                // 	break;
            default:
                break;
        }

        preorderFunction(temp->leftBranch);
        preorderFunction(temp->rightBranch);
    }
} 

void inorderFunction(treeNode *temp)
{
    if(temp)
    {
        if(temp->type == OPERATOR)
        {
            printf("(");
        }
        inorderFunction(temp->leftBranch);

        switch(temp->type)
        {
            case VALUE:
                printf("%.2f", temp->num);
                break;
            case OPERATOR:
                printf("%c", temp->operator);
                break;
            case VARIABLE:
                printf("%c%.2f", temp->nodeID, temp->num);
                break;
            default:
                break;
        }

        inorderFunction(temp->rightBranch);

        if (temp->type == OPERATOR)
        {
            printf(")");
        }
    }
}

void searchInorderFunction( treeNode *temp, char tempVal, float tempValue)
{
	if(!temp)
	{
		return;
	}

	searchInorderFunction(temp->leftBranch, tempVal, tempValue);

	if(temp->type == VARIABLE && temp->nodeID == VALUE)
	{
		if(temp->num == 0)
		{
			printf("value replaced with %f\n", tempValue);
			temp->num = tempValue;
			temp->type = VALUE;
		}
		else
		{
			printf("value replaced with (%f*%f) which is equal to %f\n", temp->num, tempValue, (temp->num * tempValue));
			temp->num = (temp->num * tempValue);
			temp->type = VALUE;
		}
	}
	searchInorderFunction(temp->rightBranch, tempVal, tempValue);
}

void postorderFunction(treeNode *temp)
{
    if(temp)
    {
        postorderFunction(temp->leftBranch);
        postorderFunction(temp->rightBranch);

        switch(temp->type)
        {
            case VARIABLE:
                printf("%c%.2f ", temp->nodeID, temp->num);
                break;
            case OPERATOR:
                printf("%c ", temp->operator);
                break;
            case VALUE:
                printf("%.2f ", temp->num);
                break;
            default:
                break;
        }
    }
}

void updateFunction(treeNode * start)
{
	float val = 0.0;
	char id;
	printf("please enter the variable that you want to replace\n");
	scanf("%c", &id);
	getchar();
	printf("please enter what value you want to replace it with\n");
	scanf("%f", &val);
	getchar();
	printf("ok i will reaplace %c with %.2f\n", id, val);

	return;
}

float checkExpression(treeNode * temp)
{
	if (temp->type  == VARIABLE)
	{
		printf("no variables to evaluate, returning to main menu...\n");
		exit(0);
	}
	else if(temp->type == VALUE)
	{
		return temp->num;
	}
	else
	{
		float yVal = 0;
		float xVal = 0;
		yVal = checkExpression(temp->rightBranch);
		xVal = checkExpression(temp->leftBranch);

		if(temp->operator == '*')
		{
			return xVal*yVal;
		}
		else if (temp->operator == '/')
		{
			return xVal/yVal;
		}
		else if(temp->operator == '+')
		{
			return xVal+yVal;
		}
		else if(temp->operator == '-')
		{
			return xVal-yVal;
		}
		else
		{
			return 0;
		}
	}
}