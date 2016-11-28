#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//struct for the nodes for the avl tree
struct avlNode
{
    char * avlNodeValue;
    struct avlNode *leftBranch;
    struct avlNode *rightBranch;
    int frequency;
    int height;
};
typedef struct avlNode avlNodeInit;

//struct for the avl tree and root
struct avlTree
{
    struct avlNode *avlRoot; 
};

typedef struct avlTree avlTreeInit;


//creates the actual avl tree when the program is initiated, 
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

//called by the insert function that uses the inputed values to create a new node on the avl search tree
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


//used to keep track of height while inserting the nodes into the avl tree
//wasnt able to figure out how to implement this into option 5 on the main menu though
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

//keeps track of the avl tree balance and makes sure both sides are evenly split.
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


//takes the node inputted and does a right right rotation and returns it
avlNodeInit * doubleRightRotation(avlNodeInit * node)
{

    avlNodeInit *a = node;
    avlNodeInit *b = a->rightBranch;

    a->rightBranch = b->leftBranch;
    b->leftBranch = a;

    return b;
}

//takes the node inputted and does a left left rotation and returns it
avlNodeInit * doubleLeftRotation(avlNodeInit * node)
{

    avlNodeInit *a = node;
    avlNodeInit *b = a->leftBranch;

    a->leftBranch = b->rightBranch;
    b->rightBranch = a;

    return b;
}

//takes the node inputted and does a right left rotation and returns it
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

//takes the node inputted and does a left right rotation and returns it
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


//main brain for balancing the avl tree which recursively calls itself calling the 
//aforementioned rotation functions as needed until the avl tree nodes are properly balanced
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


//balances the avl search tree and it's nodes that are inputted into the function
void balanceAVLTree(avlTreeInit *tree)
{
    avlNodeInit *tempRoot = NULL;

    tempRoot = balanceAVLNode(tree->avlRoot);

    if(tempRoot != tree->avlRoot)
    {
        tree->avlRoot = tempRoot;
    }
}

//main function that inserts all the parsed values into the avl search tree and creates the avl search tree
//if it wasnt already there and keeps track of the frequency of each node entered and then proceeds
//to call the main balancing function to balane the tree.
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
        while(next != NULL)
        {
            last = next;
            if(strcmp(avlNodeValue, next->avlNodeValue) > 0)
            {
                next = next->rightBranch;
            }
            else if(strcmp(avlNodeValue, next->avlNodeValue) < 0)
            {
                next = next->leftBranch;
            }
            else if(strcmp(avlNodeValue, next->avlNodeValue) == 0)
            {
                next->frequency++;
                printf("Key: %s frequency: [%d]\n", next->avlNodeValue, next->frequency);
                return;
            }
        }
        node = createAVLNode(avlNodeValue);
        strcpy(node->avlNodeValue, avlNodeValue);
        if(strcmp(avlNodeValue, last->avlNodeValue) > 0)
        {
            printf("Key: %s frequency: %d\n", avlNodeValue, last->frequency);
            last->rightBranch = node;
        }
        else if(strcmp(avlNodeValue, last->avlNodeValue) < 0)
        {
            printf("Key: %s frequency: %d\n", avlNodeValue, last->frequency);
            last->leftBranch = node;
        }
        else if(strcmp(avlNodeValue, last->avlNodeValue) == 0)
        {
            last->frequency++;
            return;
        }
    }
    balanceAVLTree(tree);
}


//parses through the text file of data and recursively calls the insert function while parsing each node
//have it set to skip over empty lines in order to prevent seg faults
void initialize (FILE * fp, avlTreeInit * tree)
{
    char line[500];
    char * key;

    while(fgets(line, sizeof(line), fp))
    {
        if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }

        key = strtok(line, " ");

        if( key != NULL)
        {
            insert(tree, key);
        }

        while((key = strtok(NULL, " ")) != NULL)
        {
            insert(tree, key);
        }   

        memset(line, '\0', strlen(line));
    }

    printf("file successfully inserted and initialized\n");
}


//searches through the entire tree to find the matching value inputted and displays the frequency of that value
void search(avlTreeInit *tree, char * searchValue)
{
    int tempFrequency = -1;
    avlNodeInit * tempRoot = tree->avlRoot;
    while( tempRoot != NULL && (strcmp(tempRoot->avlNodeValue, searchValue) != 0))
    {
        if(strcmp(tempRoot->avlNodeValue, searchValue) < 0)
        {
            if(tempRoot->rightBranch == NULL)
            {
                break;
            }
            tempRoot = tempRoot->rightBranch;
            if(strcmp(tempRoot->avlNodeValue, searchValue) == 0)
            {
                tempFrequency = 0;
                tempFrequency = tempRoot->frequency;
                break;
            }
        }
        else if(strcmp(tempRoot->avlNodeValue, searchValue) > 0)
        {
            if(tempRoot->leftBranch == NULL)
            {
                break;
            }
            tempRoot = tempRoot->leftBranch;
            if(strcmp(tempRoot->avlNodeValue, searchValue) == 0)
            {
                tempFrequency = 0;
                tempFrequency = tempRoot->frequency;

                break;
            }
        }
    }
    if(tempFrequency > 0)
    {
        printf("key: %s, frequency: %d\n", tempRoot->avlNodeValue, tempFrequency);
    }
    else
    {
        printf("no_such_key\n");
    }
}

//searches through the avl search tree to find values that have higher frequencies
//and prints them out for the user (not fully functional)
void frequencySearch(avlTreeInit *tree, int frequencyCompare)
{
    avlNodeInit *tempRoot = tree->avlRoot;

    while (tempRoot != NULL)
    {
        if(frequencyCompare < tempRoot->frequency)
        {
            printf("key: %s, frequency: %d\n", tempRoot->avlNodeValue, tempRoot->frequency);
            tempRoot = tempRoot->rightBranch;

        }
        else
        {
            tempRoot = tempRoot->leftBranch;
        }
    }
}

//searches through the avl search tree to find the inputted value by the user and removes it
//from the avl search tree, reducing the frequency by 1 (not fully functional)
void delete(avlTreeInit *tree, char * keyRemove)
{
    int tempFrequency = -1;
    avlNodeInit * tempRoot = tree->avlRoot;
    while( tempRoot != NULL && (strcmp(tempRoot->avlNodeValue, keyRemove) != 0))
    {
        if(strcmp(tempRoot->avlNodeValue, keyRemove) < 0)
        {
            if(tempRoot->rightBranch == NULL)
            {
                break;
            }
            tempRoot = tempRoot->rightBranch;
            if(strcmp(tempRoot->avlNodeValue, keyRemove) == 0)
            {
                tempFrequency = 0;
                tempFrequency = tempRoot->frequency - 1;
                tempRoot->frequency--;
                free(tempRoot);
                break;
            }
        }
        else if(strcmp(tempRoot->avlNodeValue, keyRemove) > 0)
        {
            if(tempRoot->leftBranch == NULL)
            {
                break;
            }
            tempRoot = tempRoot->leftBranch;
            if(strcmp(tempRoot->avlNodeValue, keyRemove) == 0)
            {
                tempFrequency = 0;
                tempFrequency = tempRoot->frequency - 1;
                tempRoot->frequency--;
                free(tempRoot);
                break;
            }
        }
    }
    if(tempFrequency > -1)
    {
        printf("key: %s, frequency: %d\n", tempRoot->avlNodeValue, tempFrequency);
    }
    else
    {
        printf("no_such_key\n");
    }   
}

//main function that holds the switch case that controls all the different functions
int main()
{

    int userInput = 0;
    char fileName[256];
    int frequencyCompare = 0;
    char keyRemove[25];
    char keyInsert[25];
    char keySearch[25];
    avlTreeInit *tree = NULL;
    tree = createAVL();
    insert(tree, "");

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
                insert(tree, keyInsert);
                break;
            case 4:
                printf("remove key: ");
                scanf("%s", keyRemove);
                delete(tree, keyRemove);
                break;
            case 5:
                printf("could not figure out how to implement in time.\n");
                break;
            case 6:
                printf("frequency: ");
                scanf("%d", &frequencyCompare);
                frequencySearch(tree, frequencyCompare);
                break;
            case 7:
                printf("goodbye!\n"); 
                exit(1);
                break;
        }
    }
    return 0;
}
