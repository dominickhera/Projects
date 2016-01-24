#include"main.h"

int main(int argc, char* argv[]) {

    FILE * openData;
    FILE * openTemplate;
    FILE * outputFile;
    char word[50];
    char line[256];
    char variableArray[50];
    int i = 0;
    int length = 0;

    if (argc != 4) {
        printf(" incorrect number of arguments given\n");
        return 1;
    }
    openData = fopen(argv[1], "r");
    if (openData == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }
    openTemplate = fopen(argv[2], "r");
    if (openTemplate == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }

    outputFile = fopen(argv[3], "w");
    if (openData == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }

    while(fgets(line, 256, openData ) != NULL){

        length = strlen(line);
        line[length-1] = '\0';

        for (int i = 0; i < length; i++) {
             while(line[i] == '=') {
		
                            }
        }

        setValue(variableArray, line);
        printf(getValue(variableArray));
        fprintf(outputFile, "%s\n", line);
    }

    fclose(openTemplate);
    fclose(openData);
    fclose(outputFile);
    return 0;
}
