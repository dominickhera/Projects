#include "q1Functions.h"

int main(int argc, char* argv[])
{
    int userInput = 0;
    char * expression = argv[1];
    treeNode * start = parseExpression(expression);

    while (userInput != 7)
    {

        printf("(1) Display\n(2) Preorder\n(3) Inorder\n(4) Postorder\n(5) Update\n(6) Calclulate\n(7) Exit\n");
        scanf("%d", &userInput);

        switch(userInput)
        {
            case 1:
                printf("does not print.\n sorry...\n");
                break;
            case 2:
                preorderFunction(start);
                printf("\n");
                break;
            case 3:
                inorderFunction(start);
                printf("\n");
                break;
            case 4:
                postorderFunction(start);
                printf("\n");
                break;
            case 5:
            	updateFunction(start);
                printf("\n");
                break;
            case 6:
                printf("%f\n", checkExpression(start));
                break;
            case 7:
                printf("goodbye\n");
                exit(1);
            default:
                printf("please enter a number between 1 and 7\n");
        }
    }

    return 0;
}
