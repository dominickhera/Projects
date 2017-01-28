#include <stdio.h>
#include <string.h>

#include "storeval.h"

int main() {
    char* test;

    /**
     * Empty
     */
    test = getValue("hello");
    if (!test) {
        printf("PASS: empty\n");
    } else {
        printf("FAIL: empty\n");
    }
    printf("\n");

    /**
     * hello = world
     */
    if (setValue("hello", "world")) {
        printf("PASS: basic set\n");
    } else {
        printf("FAIL: basic set\n");
    }
    test = getValue("hello");
    if (test) {
        printf("PASS: basic get\n");
    } else {
        printf("FAIL: basic get\n");
    }
    if (strcmp(test, "world") == 0) {
        printf("PASS: retrieved %s\n", test);
    } else {
        printf("FAIL: retrieved %s\n", test);
    }
    printf("\n");

    /**
     * yellow = submarine
     */
    if (setValue("yellow", "submarine")) {
        printf("PASS: basic set 2\n");
    } else {
        printf("FAIL: basic set 2\n");
    }
    test = getValue("yellow");
    if (test) {
        printf("PASS: basic get 2\n");
    } else {
        printf("FAIL: basic get 2\n");
    }
    if (strcmp(test, "submarine") == 0) {
        printf("PASS: retrieved %s\n", test);
    } else {
        printf("FAIL: retrieved %s\n", test);
    }
    printf("\n");

    /**
     * what = ?
     */
    test = getValue("what");
    if (!test) {
        printf("PASS: empty\n");
    } else {
        printf("FAIL: empty\n");
    }
    printf("\n");


    /**
     * yellow = double
     */
    if (setValue("yellow", "double")) {
        printf("PASS: set overwrite\n");
    } else {
        printf("FAIL: set overwrite\n");
    }
    test = getValue("yellow");
    if (test) {
        printf("PASS: get overwrite\n");
    } else {
        printf("FAIL: get overwrite\n");
    }
    if (strcmp(test, "double") == 0) {
        printf("PASS: retrieved %s\n", test);
    } else {
        printf("FAIL: retrieved %s\n", test);
    }


    return 0;
}
