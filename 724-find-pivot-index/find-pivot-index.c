int pivotIndex(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    int lsum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (lsum == sum - lsum - nums[i])
            return i;
        lsum += nums[i];
    }
    return -1;
}