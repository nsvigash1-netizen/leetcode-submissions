int largestAltitude(int* gain, int gainSize) {
    int max = 0;
    int sum = 0;
    for (int i = 0; i < gainSize; i++) {
        sum+=gain[i];
        if (sum > max)
            max = sum;
    }
    return max;
}
