char* removeStars(char* s) {
    int len = strlen(s);
    char* newStr = (char*)malloc((sizeof(char) * len) + 1);
    int idx = 0;
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            idx--;
        } else {
            newStr[idx++] = s[i];
        }
    }
    newStr[idx] = '\0';
    return newStr;
}