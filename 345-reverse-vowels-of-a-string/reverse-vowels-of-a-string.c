#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseVowels(char* s) {
    int length = strlen(s);
    char *result = malloc(length + 1);
    strcpy(result, s);

    // O(1) vowel check (i used strchr which was inefficient)
    bool isVowel[128] = {0};
    isVowel['a'] = isVowel['e'] = isVowel['i'] = isVowel['o'] = isVowel['u'] = true;
    isVowel['A'] = isVowel['E'] = isVowel['I'] = isVowel['O'] = isVowel['U'] = true;

    int l = 0, r = length - 1;
    while (l < r) {
        while (l < r && !isVowel[(unsigned char) result[l]]) l++;
        while (l < r && !isVowel[(unsigned char) result[r]]) r--;
        if (l < r) {
            char tmp = result[l];
            result[l++] = result[r];
            result[r--] = tmp;
        }
    }
    return result;
}