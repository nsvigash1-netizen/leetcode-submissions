#include <string.h>
char* mergeAlternately(char* word1, char* word2) {
    int idx = 0, i = 0, j = 0;
    
    int len = strlen(word1) + strlen(word2) + 1;
    char* result = (char*)malloc(len);

    while (word1[i] != '\0' && word2[j] != '\0') {
        result[idx++] = word1[i++];
        result[idx++] = word2[j++];
    }

    while (word1[i] != '\0') result[idx++] = word1[i++];
    while (word2[j] != '\0') result[idx++] = word2[j++];
    result[idx] = '\0';
    return result;
}