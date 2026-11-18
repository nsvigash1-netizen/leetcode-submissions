void dfs(int ** isConnected, int* isConnectedColSize, int curIdx, bool* isVisited) {
    for (int i = 0; i < isConnectedColSize[curIdx]; i++) {
        if (isConnected[curIdx][i]) {
            if (!isVisited[i]) {
                isVisited[i] = 1;
                dfs(isConnected, isConnectedColSize, i, isVisited);
            }
        }
    }
}
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
#define MAXLEN 200
    bool isVisited[MAXLEN] = {0};
    int count = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (!isVisited[i]) {
            isVisited[i] = 1;
            count++;
            dfs(isConnected, isConnectedColSize, i, isVisited);
        }
    }
    return count;
}