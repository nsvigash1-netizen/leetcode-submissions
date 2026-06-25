/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Approach 1- Prefix & Suffix variables
// Approach 2- Suffix only

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    // Pass 1: prefix products
    answer[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        answer[i] = answer[i-1] * nums[i-1];
    }

    // Pass 2: multiply suffix products
    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}