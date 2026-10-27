int romanToInt(char* s) {
    int romanArr[128];
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
        if (romanArr[(unsigned char)s[i + 1]] > romanArr[(unsigned char)s[i]]) {
            result += romanArr[(unsigned char)s[i + 1]];
            result -= romanArr[(unsigned char)s[i]];
            i++;
        } else {
            result += romanArr[(unsigned char)s[i]];
        }
        i++;
    }
    return result;
}