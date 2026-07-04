/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//#define ABS(x) ((x) < 0 ? -(x) : (x))

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * asteroidsSize + 1);
    int size = 0;

    for (int i = 0; i < asteroidsSize; i++) {
        if (asteroids[i] > 0) {
            result[size++] = asteroids[i];
        } else {
            // asteroids[i] is negative (moving left)
            int alive = 1;
           
                while (size > 0 && result[size - 1] > 0 && alive) {
                    if (ABS(result[size - 1]) > ABS(asteroids[i])) {
                        alive = 0; // current asteroid destroyed
                    } else if (ABS(result[size - 1]) <
                               ABS(asteroids[i])) {
                        size--; // stack top (right moving asteroid) destroyed; loop continues to check next stack top
                    } else {
                        size--; // both asteroids destroyed
                        alive = 0;
                    }
                }
                if (alive) {
                    result[size++] = asteroids[i];
                }
            }
        }
    
    *returnSize = size;
    return result;
}