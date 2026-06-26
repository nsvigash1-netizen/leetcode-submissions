bool isSubsequence(char* s, char* t) {
    int sIdx = 0;
    int i = 0;

    while (t[i] != '\0') {
        if (s[sIdx] != '\0' && s[sIdx] == t[i])
            sIdx++;
        i++;
    }
    return s[sIdx] == '\0';
}