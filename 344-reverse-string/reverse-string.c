void reverseString(char* s, int sSize) {
    int reversed[sSize];

    for (int i = 0; i < sSize; i++) {
        reversed[sSize - i - 1] = s[i];
    }

    for (int j = 0; j < sSize; j++) {
        s[j] = reversed[j];
    }
}