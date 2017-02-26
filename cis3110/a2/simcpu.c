#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char line[256]; 
    char fileName[256];
    char fileStorage[500][500]; 
    int detailFlag = 0;
    int verboseFlag = 0;
    int roundRobinFlag = 0;
    int count = 0;   
 

    /*if(strcmp(argv[1], "-d") != 0 && strcmp(argv[1], "-r") != 0)
    {
      printf("this is argv[2]: %s\n", argv[1]);   
      //fp = fopen(argv[1], "r");  
    }

    if(!feof(stdin))
    {
        printf("could not find file, exiting program...\n");
        exit(1);
    }
   */ 
    while(fgets(line, sizeof(line), stdin) != NULL)
    {
        strcpy(fileStorage[count], line);
        printf("%s", fileStorage[count]);
        count++;
        //printf("%s", line);
    }

    fclose(fp);

    return 0;
}
