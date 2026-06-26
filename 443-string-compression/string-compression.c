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

        // write character 
        chars[idx++] = curChar;

        // write count only if > 1
        if (c > 1) {
            // manual int to chars (not using snprintf)
            int start = idx;
            while (c > 0) {
                chars[idx++] = '0' + (c % 10);
                c/=10;
            }
            // flipping the digits (written in reverse)
            int end = idx - 1;
            while (start < end) {
                char tmp = chars[start];
                chars[start++] = chars[end];
                chars[end--] = tmp;
            }
        }
    }
    return idx;
}