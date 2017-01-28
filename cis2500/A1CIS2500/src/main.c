#include "open.h"
#include "scan.h"


int main(int argc, char* argv[]) 
{
    char * openData = argv[1];
    char * openTemplate = argv[2];
    char * outputFile = argv[3];
    // FILE * openData;
    // FILE * openTemplate;
    // FILE * outputFile;
    // char line[255];
     char value[255];
     char key[255];
    // char word[25];
    // int wordLength = 0;
    // int length = 0;
    // int argNum = 0;
    // int argLength = 0;
    // int sucNum = 0;
    // int updateCounter = 0;


    //makes sure 4 arguements are included, opens all the necessary files based on what the user enters
    if (argc != 4) 
    {
        printf(" incorrect number of arguments given\n");
        return 1;
    }

    dataOpen(openData, key, value);
    templateOpen(openTemplate, outputFile, key, value);

    // // prints out stats about program execution, and closes all files to prevent memory leaks
    // printf("%d Variables Successfully Replaced\nProcess Executed Successfully\n", updateCounter);

    // closeFiles(openTemplate, openData, outputFile);

    return 0;
}
