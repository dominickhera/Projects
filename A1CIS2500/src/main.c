#include"main.h"

int main() {

    FILE * openData;
    FILE * openTemplate;
    FILE * outputFile;
    char word[50];
    char line[256];
    char variableArray[50];
    int i;
    int length;

    openData = fopen("./assets/data.txt", "r");
    if (openData == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }
    openTemplate = fopen("./assets/template.txt", "r");
    if (openTemplate == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }

    outputFile = fopen("./assets/output.txt", "w");
    if (openData == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }


    while(fgets(line, 256, openData ) != NULL){
        int length = 0;

        length = strlen(line);
        line[length-1] = '\0';

        for (int i = 0; i < length; i ++ {
                if (line[i] == '=') {
		
                }
                }

                setValue(variableArray, line);
                printf(getValue(variableArray));
                fprintf(outputFile, "%s\n", line);
                }

                /*
                   while (fscanf(openTemplate, "%s", word) != EOF)
                   {
                   length = strlen(word);
                   for (i = 0; i < length; i++)
                   :                   {
                   if (ispunct(word[i])) 
                   {
                   length = i;
                   break;
                   }
                   }

                   printf("%s%c", word, fgetc(openTemplate));
                   }
                 */
    fclose(openTemplate);
    fclose(openData);
    fclose(outputFile);
    return 0;
}
