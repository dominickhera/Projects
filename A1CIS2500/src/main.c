#include "main.h"

int main(){
    FILE * openData;
    FILE * openTemplate;
    FILE * outputFile;
    char line[256];

    openTemplate = fopen("template.txt", "r");
    if (openTemplate == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }
/*
    outputFile = fopen("outputFile.txt", "w");

    while(fgets(line, 256, openTemplate) != NULL){
        int length = 0;

        length = strlen(line);
        line[length-1] = '\0';

        for (int i = 0; i < length; i++){
            if(line[i] == 'o') {
                line[i] = 'z';
            }
        }

        fprintf(outputFile, "%s\n", line);

    }
*/
fclose(openData);
fclose(outputFile);
fclose(openTemplate);


return 0;
}
