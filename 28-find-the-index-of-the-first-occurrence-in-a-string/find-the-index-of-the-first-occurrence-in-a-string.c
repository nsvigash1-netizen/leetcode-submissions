int strStr(char* haystack, char* needle) {
    if (!*needle) return 0;

    for (int i = 0; haystack[i]; i++) {
        int j = 0;
        while (needle[j] && haystack[i + j] == needle[j]) {
            j++;
        }
        if (!needle[j]) return i;       // matched the whole needle
        if (!haystack[i + j]) return -1; // haystack ran out, no later start can match
    }
    return -1;
}