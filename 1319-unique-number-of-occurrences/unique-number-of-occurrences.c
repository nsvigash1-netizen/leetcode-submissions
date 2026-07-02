#define OFFSET 1000
#define ARR_LENGTH 1001
#define VAL_RANGE 2001

bool uniqueOccurrences(int* arr, int arrSize) {
    
    // isCounted checks if value is already counted
    // occurence[i] specifies if any element has i iterations in arr

    bool isCounted[VAL_RANGE] = {false};
    bool occurence[ARR_LENGTH] = {false};

    for (int i = 0; i < arrSize; i++) {
        if (!isCounted[OFFSET + arr[i]]) {
            int c = 0;
            int j = 0;

            while (j < arrSize) {
                if (arr[j] == arr[i])
                    c++;
                j++;
            }

            isCounted[OFFSET + arr[i]] = true;
            if (occurence[c])
                return false;

            occurence[c] = true;
        }    
    }

    return true;
}