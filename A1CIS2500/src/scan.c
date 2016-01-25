#include"main.h"
int valueSetter (FILE * openData, int nlength)
 {

int argNum = 0;
int argLength = 0;
int sucNum = 0;
//int nlength = 0;
char line [256];
char value[256];
char key[256];



nlength = strlen(line);
          line[nlength+1] = '\0';
  
           for (int i = 0; i < nlength; i++)
           {
               while(line[i] == '=')
               {
                   argLength = i;
                   i++;
                   argNum++;
               }
           }
   
           strncpy(key, line, argLength);
           strncpy(value, line + (argLength + 1), nlength + 1);
           sucNum = setValue(key, value);
           memset(key, 0, nlength);
           memset(value, 0, nlength);

return 0;
}
