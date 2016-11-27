#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct avlNode
{
    char * avlNodeValue;
    struct avlNode *leftBranch;
    struct avlNode *rightBranch;
    int frequency;
    int height;
};

typedef struct avlNode avlNodeInit;

struct avlTree
{
    struct avlNode *avlRoot; 
};

typedef struct avlTree avlTreeInit;

avlTreeInit *createAVL()
{
    avlTreeInit *tree = NULL;
    if((tree = malloc(sizeof(avlTreeInit))) == NULL)
    {
        return NULL; 
    }

    tree->avlRoot = NULL;
    return tree; 
}

avlNodeInit *createAVLNode(char *avlNodeValue)
{
    avlNodeInit *node = NULL;

    if((node = malloc(sizeof(avlNodeInit))) == NULL)
    {
        return NULL;
    }

    node->avlNodeValue = malloc(sizeof(char) * 50);
    node->leftBranch = NULL;
    node->rightBranch = NULL;
    node->height = 1;
    node->frequency = 1;
    strcpy(node->avlNodeValue, avlNodeValue);
    return node;
}

avlNodeInit * doubleRightRotation(avlNodeInit * node)
{
    avlNodeInit* a = node->leftBranch;
    a->leftBranch = node->rightBranch;
    node->rightBranch = a;

    return a;
}

avlNodeInit * doubleLeftRotation(avlNodeInit * node)
{
    avlNodeInit* a = node->rightBranch;
    a->rightBranch = node->leftBranch;
    node->leftBranch = a;

    return a;
}

avlNodeInit * rightLeftRotation(avlNodeInit * node)
{

    avlNodeInit* a = node->leftBranch;
    avlNodeInit* b = a->rightBranch;
    node->leftBranch = b->rightBranch;
    a->rightBranch = b->leftBranch;
    b->leftBranch = a;
    b->rightBranch = node;

    return b;

}

avlNodeInit * leftRightRotation(avlNodeInit * node)
{

    avlNodeInit* a = node->rightBranch;
    avlNodeInit* b = a->leftBranch;
    node->rightBranch = b->leftBranch;
    a->leftBranch = b->rightBranch;
    b->rightBranch = a;
    b->leftBranch = node;

    return b;
}


avlNodeInit * balanceAVLNode (avlNodeInit *node)
{

    printf("poop nuts\n");

    return 0;

}


void balanceAVLTree(avlTreeInit *tree)
{
    avlNodeInit *tempRoot = NULL;

    tempRoot = balanceAVLNode(tree->avlRoot);

    if(tempRoot != tree->avlRoot)
    {
        tree->avlRoot = tempRoot;
    }
}

void insert(avlTreeInit *tree, char * avlNodeValue)
{
    avlNodeInit *node = NULL;
    avlNodeInit *last = NULL;
    avlNodeInit *next = NULL;

    if(tree->avlRoot == NULL)
    {
        node = createAVLNode(avlNodeValue);
        strcpy(node->avlNodeValue, avlNodeValue);
        tree->avlRoot = node;
    }
    else
    {
        next = tree->avlRoot;
        // printf("1\n");
        while(next != NULL)
        {
            last = next;
            if(strcmp(avlNodeValue, next->avlNodeValue) > 0)
            {
                next = next->leftBranch;
            }
            else if(strcmp(avlNodeValue, next->avlNodeValue) < 0)
            {
                next = next->rightBranch;
            }
            else if(strcmp(avlNodeValue, next->avlNodeValue) == 0)
            {
                printf("the frequency of %s is %d\n", last->avlNodeValue, next->frequency);
               last->frequency++;
               // node->frequency = next->frequency;

               return;
            }
            // printf("15\n");
        }
        // printf("16\n");
        node = createAVLNode(avlNodeValue);
        // printf("17\n");
        strcpy(node->avlNodeValue, avlNodeValue);
        // printf("18\n");
        if(strcmp(avlNodeValue, last->avlNodeValue) > 0)
        {
            // printf("19\n");
            last->leftBranch = node;
            // printf("20\n");
        }
        if(strcmp(avlNodeValue, last->avlNodeValue) < 0)
        {
            // printf("21\n");
            last->rightBranch = node;
        }
        // printf("23\n");
    }
// printf("24\n");
    // balanceAVLTree(tree);
}

void initialize (FILE * fp)
{
    char line[256];
    char * key;
    avlTreeInit *tree = NULL;
    tree = createAVL();

    while(fgets(line, sizeof(line), fp))
    {
            key = strtok(line, " ");
            insert(tree, key);
            while((key = strtok(NULL, " ")) != NULL)
            {;
                insert(tree, key);
            }   
            memset(line, '\0', strlen(line));
    }
}

int main()
{

    int userInput = 0;
    char fileName[256];
    char frequencyCompare[10];
    char keyRemove[25];
    char keyInsert[25];
    char keySearch[25];
    avlTreeInit *tree = NULL;

    while(userInput != 7)
    {
        printf("1. Initialization\n2. Find\n3. Insert\n4. Remove\n5. Check Height and Size\n6. Find All (above a given frequency)\n7. Exit\n\navl/> ");
        scanf("%d", &userInput);
        switch(userInput)
        { 
            case 1:
            
                printf("filename: ");
                scanf("%s", fileName); 
                FILE *fp;
                fp = fopen(fileName, "r");
                if(fp == NULL)
                {
                    printf("could not find file\n");
                    return 0;
                }
                // tree = createAVL();
                initialize(fp);	
                break;
            case 2:
                printf("find key: ");
                scanf("%s", keySearch);
                printf("key: %s, frequency: someNumber\n", keySearch);
                // insert(tree, keySearch);
                break;
            case 3:
                printf("insert key: ");
                scanf("%s", keyInsert);
                // printf("key: %s, frequency: someNumber\n", keyInsert);
                insert(tree, keySearch);
                break;
            case 4:
                printf("remove key: ");
                scanf("%s", keyRemove);
                printf("key: %s, frequency: someNumber-1\n", keyRemove);
                break;
            case 5:
                printf("height : someNumber, size: someNumber\n");
                break;
            case 6:
                printf("frequency: ");
                scanf("%s", frequencyCompare);
                printf("key: someKey, frequency: someNumber\n");
                break;
            case 7:
                printf("goodbye!\n"); 
                exit(1);
                break;
        }
    }
    return 0;
}
