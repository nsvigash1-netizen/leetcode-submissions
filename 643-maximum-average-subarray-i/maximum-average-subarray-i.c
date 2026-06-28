double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
    double result = 0;

    for (int i = 0, end = numsSize - k + 1; i < end; i++) {

        if (i == 0) {
            for (int j = 0; j < k; j++) {
                sum += nums[j];
            }
            result = sum;
        } else {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];

            if (sum > result)
                result = sum;
        }
    }
    result /= k;

    return result;
}