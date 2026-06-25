int compress(char* chars, int charsSize) {
    int idx = 0;
    int i = 0;

    while (i < charsSize) {
        char curChar = chars[i];
        int c = 0;

        // count occurrence
        while (i < charsSize && chars[i] == curChar) {
            i++;
            c++;
        }

        // write charactr 
        chars[idx++] = curChar;

        // write count only if > 1
        if (c > 1) {
            char str[12];
            snprintf(str, sizeof(str), "%d", c);
            int strIdx = 0;
            while (str[strIdx] != '\0') chars[idx++] = str[strIdx++]; 
        }
    }
    return idx;
}