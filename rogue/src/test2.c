#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
   FILE * openLevel;
    char text[200];
    //char str[900];
    openLevel = fopen(argv[1], "r");

    if (argc != 1){
        printf("not enough arguments provided\n");
        return 1;
    }

    for(int i=0; ferror(openLevel) == 0; i++){
        fscanf(openLevel, "%s", text);
    	printf("%s\n", text);
    }
    //char str[] ="10X16 de4 dw9 ds8 g8,7 M3,4 h6,5 p2,2";
    // str = text;
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",text);
    pch = strtok (text," X de dw ds g , M h p");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " X de dw ds g , M h p");
    }
    return 0;
}
