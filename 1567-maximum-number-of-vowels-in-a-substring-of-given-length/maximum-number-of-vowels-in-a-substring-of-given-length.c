int maxVowels(char* s, int k) {
    int c = 0;
    int maxVowel = 0;
    for (int i = 0, end = (int)strlen(s) - k + 1; i < end; i++) {
        if (i == 0) {
            for (int j = 0; j < k; j++) {
                // bitmasking to check vowels
                if ((0x208222 >> (s[j] & 0x1f)) & 1)
                    c++;
            }
            maxVowel = c;
        } else {
            if ((0x208222 >> (s[i - 1] & 0x1f)) & 1)
                c--;
            if ((0x208222 >> (s[i + k - 1] & 0x1f)) & 1)
                c++;
            if (c > maxVowel)
                maxVowel = c;
        }
    }
    return maxVowel;
}