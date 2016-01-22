#include "main.h"

int main(){
    FILE * openData;
    FILE * openTemplate;
    FILE * outputFile;
    char line[256];
    char dataEntry[30];
    char dataExit[30];
    int i = 0;
    openTemplate = fopen("./assets/template.txt", "r");
    if (openTemplate == NULL){
        printf("couldn't open template text file\n");
        return 1;
    }

    openData = fopen("./assets/data.txt", "r");
    if (openData == NULL) {
        printf("couldn't open data text file\n");
        return 1;
    }

    outputFile = fopen("./assets/outputFile.txt", "w");

while (fscanf(openData, "%s", line) != EOF) {
setValue(dataEntry, dataExit);
//i++;
}
/* 
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
