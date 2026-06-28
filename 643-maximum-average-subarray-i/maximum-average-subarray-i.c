double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
    double result = 0;

    for (int i = 0, end = numsSize - k + 1; i < end; i++) {

        if (i == 0) {
            for (int j = 0; j < k; j++) {
                sum += nums[j];
            }
            result = sum / k;
        } else {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];

            double avg = sum / k;
            if (avg > result)
                result = avg;
        }
    }
    return result;
}