int romanToInt(char* s) {
    int romanArr[256];
    romanArr['I'] = 1;
    romanArr['V'] = 5;
    romanArr['X'] = 10;
    romanArr['L'] = 50;
    romanArr['C'] = 100;
    romanArr['D'] = 500;
    romanArr['M'] = 1000;
    
    int i = 0;
    int result = 0;
    
    while (s[i]) {
        int diff = romanArr[(unsigned char)s[i + 1]] - romanArr[(unsigned char)s[i]];
        if (diff > 0) {
            result += diff;
            i++;
        } else {
            result += romanArr[(unsigned char)s[i]];
        }
        i++;
    }
    return result;
}