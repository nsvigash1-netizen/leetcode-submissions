char* reverseWords(char* s) {
    int n = strlen(s);
    int starts[n], lens[n];
    int c = 0;

    int i = 0;
    while (i < n) {
        while (i < n && s[i] == ' ') i++;  // skip spaces
        if (i == n) break;
        int start = i;
        while (i < n && s[i] != ' ') i++;  // find end of word
        starts[c] = start;
        lens[c] = i - start;
        c++;
    }

    char* answer = malloc(n + 1);
    int pos = 0;
    for (int j = c - 1; j >= 0; j--) {
        if (j < c - 1) answer[pos++] = ' ';
        memcpy(answer + pos, s + starts[j], lens[j]);
        pos += lens[j];
    }
    answer[pos] = '\0';
    return answer;
}