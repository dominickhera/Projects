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

int avlHeight(avlNodeInit *node)
{

    int rightBranchHeight = 0;
    int leftBranchHeight = 0;
    if(node->rightBranch)
    {
        rightBranchHeight = avlHeight(node->rightBranch);
    }

    if (node->leftBranch)
    {
        leftBranchHeight = avlHeight(node->leftBranch);
    }

    return rightBranchHeight > leftBranchHeight ? ++rightBranchHeight : ++leftBranchHeight;
}

int balanceTrack(avlNodeInit *node)
{

    int balanceTrackInt = 0;
    if(node->rightBranch)
    {
        balanceTrackInt = balanceTrackInt - avlHeight(node->rightBranch);
    }

    if(node->leftBranch)
    {
        balanceTrackInt = balanceTrackInt + avlHeight(node->leftBranch);
    }

    return balanceTrackInt;

}

avlNodeInit * doubleRightRotation(avlNodeInit * node)
{

    avlNodeInit *a = node;
    avlNodeInit *b = a->rightBranch;

    a->rightBranch = b->leftBranch;
    b->leftBranch = a;

    return b;
}

avlNodeInit * doubleLeftRotation(avlNodeInit * node)
{

    avlNodeInit *a = node;
    avlNodeInit *b = a->leftBranch;

    a->leftBranch = b->rightBranch;
    b->rightBranch = a;

    return b;
}

avlNodeInit * rightLeftRotation(avlNodeInit * node)
{

    avlNodeInit *a = node;
    avlNodeInit *b = a->rightBranch;
    avlNodeInit *c = b->leftBranch;

    a->rightBranch = c->leftBranch;
    b->leftBranch = c->rightBranch;
    c->rightBranch = b;
    c->leftBranch = a;

    return c;
}

avlNodeInit * leftRightRotation(avlNodeInit * node)
{

    avlNodeInit *a = node;
    avlNodeInit *b = a->leftBranch;
    avlNodeInit *c = b->rightBranch;

    a->leftBranch = c->rightBranch;
    b->rightBranch = c->leftBranch;
    c->leftBranch = b;
    c->rightBranch = a;

    return c;
}


avlNodeInit * balanceAVLNode (avlNodeInit *node)
{
    avlNodeInit * tempRoot = NULL;

    if(node->rightBranch)
    {
        node->rightBranch = balanceAVLNode(node->rightBranch);
    }
    if(node->leftBranch)
    {
        node->leftBranch = balanceAVLNode(node->leftBranch);
    }
    int balanceTrackInt = balanceTrack(node);

    if(balanceTrackInt <= -2)
    {
        if(balanceTrack(node->rightBranch) >= 1)
        {
            tempRoot = rightLeftRotation(node);
        }
        else
        {
            tempRoot = doubleRightRotation(node);
        }
    }
    else if(balanceTrackInt >= 2)
    {
        if(balanceTrack(node->leftBranch) <= -1)
        {
            tempRoot = leftRightRotation(node);
        }
        else
        {
            tempRoot = doubleLeftRotation(node);
        }
    }
    else
    {
        tempRoot = node;
    }

    return tempRoot;
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
    // printf("1\n");
    avlNodeInit *node = NULL;
    avlNodeInit *last = NULL;
    avlNodeInit *next = NULL;

// printf("2\n");
    if(tree->avlRoot == NULL)
    {
        // printf("3\n");
        node = createAVLNode(avlNodeValue);
        // printf("4\n");
        strcpy(node->avlNodeValue, avlNodeValue);
        // printf("5\n");
        tree->avlRoot = node;
    }
    else
    {
        // printf("6\n");
        next = tree->avlRoot;
        // printf("7\n");
        while(next != NULL)
        {
            // printf("8\n");
            last = next;
            // printf("8.5\n");
            if(strcmp(avlNodeValue, next->avlNodeValue) > 0)
            {
                // printf("9\n");
                printf("Key: [%s] frequency: [%d]\n", next->avlNodeValue, next->frequency);
                next = next->leftBranch;
                // return;
            }
            else if(strcmp(avlNodeValue, next->avlNodeValue) < 0)
            {
                // printf("10\n");
                printf("Key: [%s] frequency: [%d]\n", next->avlNodeValue, next->frequency);
                next = next->rightBranch;
                // return;
            }
            else if(strcmp(avlNodeValue, next->avlNodeValue) == 0)
            {
                // printf("11\n");
                // printf("found a duplicate\n");
                printf("Key: [%s] frequency: [%d]\n", next->avlNodeValue, next->frequency);
                next->frequency++;
                return;
            }
            // printf("12\n");
        }
        // printf("13\n");
        node = createAVLNode(avlNodeValue);
        // printf("14\n");
        strcpy(node->avlNodeValue, avlNodeValue);
        // printf("15\n");
        if(strcmp(avlNodeValue, last->avlNodeValue) > 0)
        {
            // printf("16\n");
            // printf("Key: [%s] frequency: [%d]\n", last->avlNodeValue, last->frequency);
            last->leftBranch = node;
            last->frequency++;
        }
        else if(strcmp(avlNodeValue, last->avlNodeValue) < 0)
        {
            // printf("17\n");
            // printf("Key: [%s] frequency: [%d]\n", last->avlNodeValue, last->frequency);
            last->rightBranch = node;
            last->frequency++;
        }
        else if(strcmp(avlNodeValue, last->avlNodeValue) == 0)
        {
            last->frequency++;
        }
        // printf("18\n");
    }
    // printf("19\n");

    balanceAVLTree(tree);
}

void initialize (FILE * fp, avlTreeInit * tree)
{
    char line[256];
    char * key;

    while(fgets(line, sizeof(line), fp))
    {
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        key = strtok(line, " ");
        // printf("key: %s\n", key);
        insert(tree, key);
        while((key = strtok(NULL, " ")) != NULL)
        {
            // printf("key: %s\n", key);
            insert(tree, key);
        }   
        memset(line, '\0', strlen(line));
    }

    printf("file successfully inserted and initialized\n");
}

void search(avlTreeInit *tree, char * searchValue)
{
    int tempFrequency = 0;
    avlNodeInit * tempRoot = tree->avlRoot;
    while(tempRoot && (strcmp(tempRoot->avlNodeValue, searchValue) != 0))
    {
        if(strcmp(tempRoot->avlNodeValue, searchValue) < 0)
        {
            tempFrequency = 0;
            tempFrequency = tempRoot->frequency;
            tempRoot = tempRoot->rightBranch;
        }
        else if(strcmp(tempRoot->avlNodeValue, searchValue) > 0)
        {
            tempFrequency = 0;
            tempFrequency = tempRoot->frequency;
            tempRoot = tempRoot->leftBranch;
        }
    }
    printf("key: %s, frequency: %d\n", searchValue, tempFrequency);
}


// void frequencySearch(avlTreeInit *tree, int frequencySearch)
// {
//     int tempFrequency = 0;
//     avlNodeInit * tempRoot = tree->avlRoot;
//     while(tempRoot && (strcmp(tempRoot->avlNodeValue, searchValue) != 0))
//     {
//         if(strcmp(tempRoot->avlNodeValue, searchValue) < 0)
//         {
//             tempFrequency = 0;
//             tempFrequency = tempRoot->frequency;
//             tempRoot = tempRoot->rightBranch;
//         }
//         else if(strcmp(tempRoot->avlNodeValue, searchValue) > 0)
//         {
//             tempFrequency = 0;
//             tempFrequency = tempRoot->frequency;
//             tempRoot = tempRoot->leftBranch;
//         }
//     }
//     printf("key: %s, frequency: %d\n", searchValue, tempFrequency);
// }

void printNodeTest( avlNodeInit *node, int depth ) 
{
    int i = 0;
    if( node->leftBranch ) printNodeTest( node->leftBranch, depth + 2 );
    for( i = 0; i < depth; i++ ) putchar( ' ' );
    printf( "%s: %d\n", node->avlNodeValue, balanceTrack( node ) );
    if( node->rightBranch ) printNodeTest( node->rightBranch, depth + 2 );
}
/* Do a depth first traverse of a tree. */
void printTreeTest( avlTreeInit *tree ) {
    printNodeTest( tree->avlRoot, 0 );
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
    // avlNodeInit *searchNode = NULL;
    tree = createAVL();

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
                printf("loading...\n");
                initialize(fp, tree);	
                fclose(fp);
                break;
            case 2:
                printf("find key: ");
                scanf("%s", keySearch);
                search(tree, keySearch);
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
                printTreeTest(tree);
                break;
            case 6:
                printf("frequency: ");
                scanf("%s", frequencyCompare);
                // frequencySearch(tree, frequencyCompare);
                // printf("key: someKey, frequency: someNumber\n");
                break;
            case 7:
                printf("goodbye!\n"); 
                exit(1);
                break;
        }
    }
    return 0;
}
