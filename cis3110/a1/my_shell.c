#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

extern char **getln();

int main() 
{
    int i;
    int j;
    int addInt;
    int count;
    char **args; 

    while(1) 
    {
        args = getln();
        count = 0;
        for(i = 0; args[i] != NULL; i++)
        {
            count++;
        }

        for(i = 0; args[i] != NULL; i++)
        {

            if(count == 1)
            {
                if(strcmp(args[i], "exit") == 0)
                {
                    exit(1);
                }
                else
                { 
                    execvp(args[i], args);
                    // printf("Argument %d: %c\n", i, args[i][i]);
                    // break;
                }
            }
            else if(count == 2)
            {
                if(strpbrk(args[i], "-") == 0)
                {
                    // printf("%s\n", args[1]);
                    execvp(args[0], &args[i]);
                    // printf("arguement found\n");
                }
                // printf("more than one arguement\n");
                break;
            }
            else
            {
                if(strcmp(args[i], "add") == 0)
                {
                    addInt = 0;
                    for(j = 1; j < count;j++)
                    {
                        addInt += atoi(args[j]);
                        if(j == count - 1)
                        {
                            printf("%s = ", args[j]);
                        }
                        else
                        {
                            printf("%s + ", args[j]);
                        }
                    }
                    printf("%d\n", addInt);
                    break;

                }
                
                if(strcmp(args[i], "args") == 0)
                {
                    printf("argc = %d, args = ", count);
                    for(j = 1; j < count; j++)
                    {
                        if(j == count - 1)
                        {
                            printf("%s\n", args[j]);
                        }
                        else
                        {
                            printf("%s, ", args[j]);
                        }
                    }
                }
            }
        }
    }
}
