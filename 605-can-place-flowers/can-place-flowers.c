bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
    int count = 0;
    int left = 0;
    // iterate through the flowerbed except the last position
    for (int i = 0; i < flowerbedSize - 1; i++)
    {
        if (left == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0 ) {
            left = 1;
            count++;
        }
        else if (flowerbed[i] == 1) {
            left = 1;
        }
        else {
            left = 0;
        }
    }
    // last index has no flowerbed[i+1] — checked separately here
    // This is a tradeoff for not using an out-of-bounds-safe "right" variable in the loop
    if (left == 0 && flowerbed[flowerbedSize - 1] == 0) count++;
    // return 
    if (n <= count) return true;
    return false;
}

/*
approach:
1. normal if-else (can do better)
2. compressed the if-else logic into one big chunk using && || (ugly)
3. left check- Time: O(n), Space: O(1)
*/