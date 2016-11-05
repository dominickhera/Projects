#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	// int userInput = 0;
	// char expressionInput[256];
	char * expression = argv[1];
	int openBracketCount = 0;
	int closeBracketCount = 0;

	int length = strlen(expression);

	printf("%s is %d chracters long\n", expression, length);

	for (int i = 0; i < length; i++)
	{
		printf("%c\n", expression[i]);
	}

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