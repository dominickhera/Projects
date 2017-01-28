#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
FILE * openQuestion;
char fileName[150];
char line[256];
char length[256];

printf("enter question filename and location\n");
scanf("%s", fileName);

openQuestion = fopen(fileName, "r");

if (openQuestion == NULL){
	printf("could not open questionnaire\n");
	return 1;
}

while(fgets(line, 256, openQuestion) != NULL){
	length = strlen(line);
}

return 0;
}