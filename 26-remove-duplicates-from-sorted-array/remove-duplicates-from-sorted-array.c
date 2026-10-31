int removeDuplicates(int* nums, int numsSize) {
    int head = 0;
    int tail = 0;
    while (head < numsSize) {
        // if (head > numsSize) break;
        // // if (!nums[head]) break;
        if ((head > 0) && nums[head] == nums[head - 1]) {
            head++;
        } else {
            nums[tail++] = nums[head++];
        }
    }
    numsSize = tail - 1;
    return tail; 
}