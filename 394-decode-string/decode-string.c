#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_LEN 32
#define MAXLEN 100005

char* decodeString(char* s) {
    static char curStr[MAXLEN];   // single reusable buffer, no malloc
    int numStack[S_LEN];
    int idxStack[S_LEN];          // stores START INDEX in curStr, not a copy of it

    int curNum = 0;
    int numIdx = 0;
    int stkIdx = 0;
    int curStrIdx = 0;

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if ((unsigned char)(s[i] - '0') < 10) {
            curNum = curNum * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            numStack[numIdx++] = curNum;
            idxStack[stkIdx++] = curStrIdx;   // remember where this bracket's content starts
            curNum = 0;
        } else if (s[i] == ']') {
            int reps = numStack[--numIdx];
            int start = idxStack[--stkIdx];
            int segLen = curStrIdx - start;    // length of the "encoded_string" just built

            // duplicate the segment (reps - 1) more times, right after itself
            for (int r = 1; r < reps; r++) {
                memcpy(curStr + curStrIdx, curStr + start, segLen);
                curStrIdx += segLen;
            }
        } else {
            curStr[curStrIdx++] = s[i];
        }
    }

    curStr[curStrIdx] = '\0';

    // return a copy sized to fit, since curStr is static/reused
    char* result = (char*)malloc(curStrIdx + 1);
    memcpy(result, curStr, curStrIdx + 1);
    return result;
}