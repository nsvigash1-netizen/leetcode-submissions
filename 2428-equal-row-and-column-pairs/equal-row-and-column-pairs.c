#define BASE 131
#define MOD  1000000007

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int rowHashes[gridSize];
    int colHashes[gridSize];

    for (int i = 0; i < gridSize; i++) {
        // Hashes for rows and cols (O(n^2), optimal)
        long long rowH = 0;
        long long colH = 0;
        for (int j = 0; j < gridSize; j++) {
            rowH = (rowH * BASE + grid[i][j]) % MOD;
            colH = (colH * BASE + grid[j][i]) % MOD;
        }
        rowHashes[i] = rowH;
        colHashes[i] = colH;
    }
    // counting hashes
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (rowHashes[i] == colHashes[j])
                count++;
        }
    }

    return count;
}