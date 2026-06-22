#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseVowels(char* s) {
    int length = strlen(s);
    char *result = malloc(length + 1);
    strcpy(result, s);

    int l = 0, r = length - 1;
    while (l < r) {
        while (l < r && !strchr("AEIOUaeiou", result[l])) l++;
        while (l < r && !strchr("AEIOUaeiou", result[r])) r--;
        if (l < r) {
            char tmp = result[l];
            result[l++] = result[r];
            result[r--] = tmp;
        }
    }
    return result;
}