#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseVowels(char* s) {
    // O(1) vowel check (i used strchr which was inefficient)
    // Also directly manipulated input data without malloc & strcpy (to reduce memory)
    bool isVowel[128] = {0};
    isVowel['a'] = isVowel['e'] = isVowel['i'] = isVowel['o'] = isVowel['u'] = true;
    isVowel['A'] = isVowel['E'] = isVowel['I'] = isVowel['O'] = isVowel['U'] = true;

    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        while (l < r && !isVowel[(unsigned char) s[l]]) l++;
        while (l < r && !isVowel[(unsigned char) s[r]]) r--;
        if (l < r) {
            char tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }
    return s;
}