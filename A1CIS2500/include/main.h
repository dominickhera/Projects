#ifndef _USERNAME_HEADER_
#define _USERNAME_HEADER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storeval.h"
#include "uthash.h"
#include <ctype.h>

 // scans the data.txt file for the variables and variable values based on the = sign, and assigns them to char arrays key or value based on which one they are, and then puts it into storeValue. also resets the memory for key and value.
char parseData (FILE * openData);
void parseTemplate(FILE * openTemplate, FILE * outputFile);
//closes all files that were opened to prevent memory leaks
void closeFiles(FILE * templateFile, FILE * dataFile, FILE * outputFile);

#endif
