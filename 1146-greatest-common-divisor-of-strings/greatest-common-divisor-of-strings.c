#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    char *cat12 = malloc(len1 + len2 + 1);
    char *cat21 = malloc(len2 + len1 + 1);
    snprintf(cat12, len1 + len2 + 1, "%s%s", str1, str2);
    snprintf(cat21, len2 + len1 + 1, "%s%s", str2, str1);

    int compatible = strcmp(cat12, cat21) == 0;
    free(cat12);
    free(cat21);

    if (!compatible) 
    {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int gcdLen = gcd(len1, len2);
    char *result = malloc(gcdLen + 1);
    strncpy(result, str1, gcdLen);
    result[gcdLen] = '\0';
    return result;
}
