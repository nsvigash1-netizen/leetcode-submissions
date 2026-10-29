bool isValid(char* s) {
    char stk[10000];
    int idx = 0;
    int i = 0;
    while (s[i]) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stk[idx++] = s[i++];
        } else {
            if ( idx > 0 && ((s[i] == ')' && stk[idx - 1] == '(') ||
                (s[i] == '}' && stk[idx - 1] == '{') ||
                (s[i] == ']' && stk[idx - 1] == '['))) {
                    idx--;
                    i++;
            } else {
                    return false;
            }
        }
    }
    // stack must be empty (for eg: "((" is valid without this)
    return idx == 0;
}