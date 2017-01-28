#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[200];
int hSize;


//creates the heap used
void createHeap()
{
    hSize = 0;
    heap[0] = 1000;
} 


//adds the number inputted into the actual heap
void addToHeap(int item)
{
    hSize++;
    heap[hSize] = item;
    int sortSize = hSize;

    while(heap[sortSize/2] > item)
    {
        heap[sortSize] = heap[sortSize/2];
        sortSize /= 2;
    }

    heap[sortSize] = item;
}


//finds smallest value and returns it first
int removeMin()
{
    int minItem;
    int lastItem;
    int child;
    int sortSize;

    minItem = heap[1];
    lastItem = heap[hSize--];

    for ( sortSize = 1; sortSize*2 <= hSize; sortSize = child)
    {
        child = sortSize * 2;

        if( child != hSize && heap[child + 1] < heap[child])
        {
            child++;
        }
        if (lastItem > heap[child])
        {
            heap[sortSize] = heap[child];
        }
        else
        {
            break;
        }

    }
    heap[sortSize] = lastItem;
    return minItem;
}

int main(int argc, char* argv[])
{
    char * file = argv[1]; 
    char line[256];
    int keyArray[256];
    int numArray[20][10];
    int i = 0;
    int j = 0;
    int heapFindNum = 0;
    int xAmount = 0;
    int numCount = 0;
    int newHigh[100];
    char *token;
    const char space[2] = " ";
    FILE *openFile;
    openFile = fopen(file, "r");

    if(openFile == NULL)
    {
        printf("Could not open %s\n", file);
        return 0;
    }

    if (argc != 1)
    {
        printf("%s loaded\n", file);

    }
    else
    {
        printf("wrong numbah hoe\n");
    }

    while(fgets(line, 256, openFile))
    {
        token = strtok(line, space);
        while(token != NULL)
        {
            if (strcmp(token,"\n") == 0)
            {
                j = 0;
                token = strtok(NULL, space);
            }
            else
            {

                numArray[i][j] = atoi(token);
                j++;
                if (j > 9)
                {
                    i++;
                    j = 0;
                }
                token = strtok(NULL, space);
            }
        }

    }

    for(int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j < 3)
            {
                numCount += numArray[i][j];
                keyArray[i] = numCount;
            }

        }
        addToHeap(keyArray[i]);
        numCount = 0;
    }

    for (int i = 0; i < 20; i++)
    {
        newHigh[i] = removeMin();
    }
    printf("\n");


//compares the smallest number to the key array and prints the rest of the data line in the specific order
    for (int i = 0; i < 20; i++)
    {
        xAmount = numArray[i][0] + numArray[i][1] + numArray[i][2];
        heapFindNum = 0;
        while(keyArray[heapFindNum] != newHigh[i])
        { 
            heapFindNum++;
        }
        for(int k = 0;k < 10; k++)
        {
            printf("%02d ",  numArray[heapFindNum][k]);
        }
        printf("\n");
    }

    return 0;
}
