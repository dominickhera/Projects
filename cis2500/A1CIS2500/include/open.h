#ifndef _USERNAME_HEADER_
#define _USERNAME_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storeval.h"
#include "uthash.h"
#include <ctype.h>

void dataOpen(char * openData, char * key, char * value);
void templateOpen(char * openTemplate, char * outputFile, char * key, char * value);

#endif
