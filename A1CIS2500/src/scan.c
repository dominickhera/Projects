#include"main.h"

int argNum = 0;
int argLength = 0;
int sucNum = 0;
int length = 0;
char line [256];
char value[256];
char key[256];


int valueSetter (char openData[], int length) {

 length = strlen(line);
          line[length+1] = '\0';
  
           for (int i = 0; i < length; i++)
           {
               while(line[i] == '=')
               {
                   argLength = i;
                   i++;
                   argNum++;
               }
           }
   
           strncpy(key, line, argLength);
           strncpy(value, line + (argLength + 1), (length + 1));
           sucNum = setValue(key, value);
           memset(key, 0, length);
           memset(value, 0, length);

return 0;
}
