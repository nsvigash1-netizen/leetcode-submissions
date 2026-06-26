#include <stdbool.h>

char* mergeAlternately(char* word1, char* word2) {
    int idx = 0, i = 0, j = 0;
    // malloced 256 bytes as an apt number near constraints
    char* result = (char*)malloc(256 * sizeof(char));
    
    while (word1[i] != '\0' || word2[j] != '\0') {
        if (word1[i] != '\0') result[idx++] = word1[i++];
        if (word2[j] != '\0') result[idx++] = word2[j++];
    }
    result[idx] = '\0';
    return result;
}