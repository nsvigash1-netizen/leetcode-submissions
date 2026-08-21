/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* array = malloc(2 * sizeof(int));
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i!=j && nums[i] + nums[j] == target) {
                array[0] = i;
                array[1] = j;
            }
        }
    }
    *returnSize = 2;
    return array;
    // intcmp(constvoid* a,constvoid* b){
    //     return(*(int*)a-*(int*)b);
    // }

    // qsort(nums, numsSize, sizeof(int), cmp);



}