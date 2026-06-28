double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;

    for (int j = 0; j < k; j++)
        sum += nums[j];

    double result = sum;

    for (int i = 1, end = numsSize - k + 1; i < end; i++) {
        sum += nums[i + k - 1] - nums[i - 1];
        if (sum > result)
            result = sum;
    }

    return result / k;
}