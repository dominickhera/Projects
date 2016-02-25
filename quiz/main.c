#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
FILE * openQuestion;
char fileName[150];

printf("enter question filename and location\n");
scanf("%s", fileName);

openQuestion = fopen(fileName, "r");

if (openQuestion == NULL){
	printf("could not open questionnaire\n");
	return 1;
}

return 0;
}