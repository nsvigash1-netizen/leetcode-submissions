#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

#define ALPHABET 26
bool closeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2)
        return false;

    // letterCount1[c] / letterCount2[c] = how many times letter c appears
    int letterCount1[ALPHABET] = {0};
    int letterCount2[ALPHABET] = {0};

    for (int i = 0; i < len1; i++)
        letterCount1[word1[i] - 'a']++;
    for (int i = 0; i < len2; i++)
        letterCount2[word2[i] - 'a']++;

    // both words must use exactly the same set of letters
    for (int i = 0; i < ALPHABET; i++) {
        if ((letterCount1[i] == 0) != (letterCount2[i] == 0))
            return false;
    }

    // sort both count arrays - if they're identical after sorting,
    // the frequency multisets match
    // e.g. {2, 3, 0, ...} == {3, 2, 0, ...}

    qsort(letterCount1, ALPHABET, sizeof(int), cmp);
    qsort(letterCount2, ALPHABET, sizeof(int), cmp);

    for (int i = 0; i < ALPHABET; i++) {
        if (letterCount1[i] != letterCount2[i])
            return false;
    }

    return true;
}