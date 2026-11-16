#define MAXLEN 1001
void search(int** rooms, int roomIdx, int* roomsColSize, bool* visited) {
    visited[roomIdx] = true;
    for (int i = 0; i < roomsColSize[roomIdx]; i++) {
        int key = rooms[roomIdx][i];
        if (!visited[key]) {
            search(rooms, key, roomsColSize, visited);
        }
    }
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[MAXLEN] = {0};
    search(rooms, 0, roomsColSize, visited);
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) return false;
    }
    return true;
}