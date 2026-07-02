#define ALPHABET 26
#define MAXN 100005

// freqOfFreq1[k] / freqOfFreq2[k] = how many letters occur exactly k times
int freqOfFreq1[MAXN] = {0};
int freqOfFreq2[MAXN] = {0};

bool closeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2)
        return false;

    memset(freqOfFreq1, 0, sizeof(freqOfFreq1));
    memset(freqOfFreq2, 0, sizeof(freqOfFreq2));

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

    // build frequency-of-frequency: e.g. "aabbb" -> one letter w/ count 2, one w/ count 3
    for (int i = 0; i < ALPHABET; i++) {
        freqOfFreq1[letterCount1[i]]++;
        freqOfFreq2[letterCount2[i]]++;
    }

    // the multiset of letter-frequencies must match (order doesn't matter,
    // e.g. "aabbb" and "bbaaa" both have {count 2, count 3})
    for (int i = 0; i <= len1; i++) {
        if (freqOfFreq1[i] != freqOfFreq2[i])
            return false;
    }

    return true;
}