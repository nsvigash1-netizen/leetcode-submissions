void moveZeroes(int* nums, int numsSize) {
    int insert = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0)
            nums[insert++] = nums[i];
    }
    while (insert < numsSize) 
        nums[insert++] = 0;
}