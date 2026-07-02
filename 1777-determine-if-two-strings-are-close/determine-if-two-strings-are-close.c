#define ALPHABET 26
#define MAXN 100005

// counts the number of iterations of chars in word1 and word2
int count1[MAXN] = {0};
int count2[MAXN] = {0};

bool closeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 != len2)
        return false;

    memset(count1, 0, sizeof(count2));   
    memset(count2, 0, sizeof(count2));   

    int freq1[ALPHABET] = {0};
    int freq2[ALPHABET] = {0};

    for (int i = 0; i < len1; i++) {
        freq1[word1[i] - 'a']++;
    }

    for (int i = 0; i < len2; i++) {
        freq2[word2[i] - 'a']++;
    }

    // character sets must match
    for (int i = 0; i < ALPHABET; i++) {
        if ((freq1[i] == 0) != (freq2[i] == 0))
            return false;
    }

    // frequency multisets must match
    for (int i = 0; i < ALPHABET; i++) {
        count1[freq1[i]]++;
        count2[freq2[i]]++;
    }


    for (int i = 0; i < len1; i++) {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}