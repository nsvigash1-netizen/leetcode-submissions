#include <stdlib.h>

#define MAX_CALLS 10001


typedef struct {
    int *times;
    int head; //index of first element still in window
    int tail; // index of next free slot (count of pings so far)
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->times = (int*)malloc(sizeof(int) * MAX_CALLS);
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->tail++] = t;
    // Slide the head forward while times are outside [t - 3000, t]
    while (obj->times[obj->head] < t - 3000) {
        obj->head++;
    }

    return obj->tail - obj->head; 
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->times);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/