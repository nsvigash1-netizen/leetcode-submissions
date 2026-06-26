#include <stdbool.h>

char* mergeAlternately(char* word1, char* word2) {
    int idx = 0;
    // malloced 256 bytes as an apt number near constraints
    char* result = (char*)malloc(256 * sizeof(char));
    bool hasVal[2] = {true, true};
    int i = 0;
    while (hasVal[0] || hasVal[1]) {
        // word1
        if (hasVal[0]) {
            if (word1[i] != '\0')
                result[idx++] = word1[i];
            else
                hasVal[0] = false;
        }
        // word2
        if (hasVal[1]) {
            if (word2[i] != '\0')
                result[idx++] = word2[i];
            else
                hasVal[1] = false;
        }
        // incrementing i
        i++;
    }
    result[idx] = '\0';
    return result;
}