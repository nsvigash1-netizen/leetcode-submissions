int longestSubarray(int* nums, int numsSize) {
    int left = 0, zeros = 0, max = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0)
            zeros++;
        while (zeros > 1) {
            if (nums[left++] == 0)
                zeros--;
        }
        if (right - left > max)
            max = right - left; // window length minus 1 (forced deletion)
    }
    return max;
}