#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int comb = numsSize - k + 1;
    int *result = malloc(comb * sizeof(int));
    int *dq = malloc(numsSize * sizeof(int)); // stores indices
    int head = 0, tail = 0;                   // dq[head..tail-1]

    for (int i = 0; i < numsSize; i++) {
        // drop the front index if it has left the window
        if (head < tail && dq[head] <= i - k) {
            head++;
        }
        // drop smaller values from the back; they can never be the max
        while (head < tail && nums[dq[tail - 1]] <= nums[i]) {
            tail--;
        }
        dq[tail++] = i;

        // window is full: front of deque is the max
        if (i >= k - 1) {
            result[i - k + 1] = nums[dq[head]];
        }
    }

    free(dq);
    *returnSize = comb;
    return result;
}