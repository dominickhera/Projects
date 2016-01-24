#include"main.h"

int main() {

    FILE * openData;
    FILE * openTemplate;
    FILE * outputFile;
    char word[50];
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

while (fscanf(openTemplate, "%s", word) != EOF)
    {
        length = strlen(word);
        for (i = 0; i < length; i++)
        {
            if (ispunct(word[i])) 
            {
                length = i;
                break;
            }
        }

        printf("%s%c", word, fgetc(openTemplate));
    }

    fclose(openTemplate);
    fclose(openData);
    fclose(outputFile);
    return 0;
}
