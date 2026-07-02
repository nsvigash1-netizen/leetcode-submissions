/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define OFFSET 1000
#define RANGE 2001


int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    bool inNums1[RANGE] = {false};
    bool inNums2[RANGE] = {false};

    for (int i = 0; i < nums1Size; i++) inNums1[nums1[i] + OFFSET] = true;
    for (int i = 0; i < nums2Size; i++) inNums2[nums2[i] + OFFSET] = true;

    int* c1 = malloc(RANGE * sizeof(int));
    int* c2 = malloc(RANGE * sizeof(int));
    int size1 = 0, size2 = 0;

    for (int v = 0; v < RANGE; v++) {
        if (inNums1[v] && !inNums2[v]) c1[size1++] = v - OFFSET;
        if (inNums2[v] && !inNums1[v]) c2[size2++] = v - OFFSET;
    }

    int** result = malloc(2 * sizeof(int*));
    result[0] = c1;
    result[1] = c2;

    *returnColumnSizes = malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;

    *returnSize = 2;
    return result;
}