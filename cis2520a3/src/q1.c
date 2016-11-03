#include <stdio.h>
#include <stdlib.h>

int main()
{
	int userInput = 0;
	char expressionInput[256];

	while (userInput != 7)
	{

		printf("(1) Display\n(2) Preorder\n(3) Inorder\n(4) Postorder\n(5) Update\n(6) Calclulate\n(7) Exit\n");
		scanf("%d", &userInput);

		switch(userInput)
		{
			case 1:
				printf("enter expression input:\n");
				scanf("%s", expressionInput);
				printf("%s is your input\n", expressionInput);
				break;
			case 2:
				printf("2\n");
				break;
			case 3:
				printf("3\n");
				break;
			case 4:
				printf("4\n");
				break;
			case 5:
				printf("5\n");
				break;
			case 6:
				printf("6\n");
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