/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include <stdlib.h>
 #include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *result = malloc(candiesSize * sizeof(bool));
    if (!result) return NULL; //malloc failed
    // max candy in a kid
    int max = 0;
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] > max)
        {
            max = candies[i];
        }
    }
    // result
    for (int i = 0; i < candiesSize; i++)
    {
        if (candies[i] + extraCandies >= max)
        {
            result[i] = true;
        }
        else
        {
            result[i] = false;
        }
    }
    // return result size
    *returnSize = candiesSize;
    // return result
    return result;
}