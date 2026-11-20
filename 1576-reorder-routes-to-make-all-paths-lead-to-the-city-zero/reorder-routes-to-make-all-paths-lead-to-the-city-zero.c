typedef struct node {
    int val;
    struct node* next;
} node;
int dfs(node** adj, int adjIdx, bool* visited) {
    int count = 0;
    for (node* ptr = adj[adjIdx]; ptr != NULL; ptr = ptr->next) {
        if (!visited[ptr->val >> 1]) {
            visited[ptr->val >> 1] = 1;
            // check if node is pointing towards neighbour (& increment count)
            if (ptr->val & 1) count++;
            count += dfs(adj, ptr->val >> 1, visited); 
        }
    }
    return count;
}
int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int count;
    // adjacency list
    node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    // use bit-packing
    // flag- 0-does not point to neighbour, 
    // 1-points to neighbour;
    for (int i = 0; i < connectionsSize; i++) {
        node* n1 = malloc(sizeof(node));
        node* n2 = malloc(sizeof(node));
        int a = connections[i][0];
        int b = connections[i][1];
        // store val of 1st ele of connections** in adj[ele2]; flag is 0 as b {adj[b]} does NOT point to a
        n1->val = (a << 1) | 0; 
        n1->next = adj[b];
        adj[b] = n1;
        // store val of 2nd ele of connections** in adj[ele1]; flag is 1 as a {adj[a]} points to b;
        n2->val = (b << 1) | 1;
        n2->next = adj[a];
        adj[a] = n2;
    }
    bool visited[50000] = {0};
    visited[0] = 1;
    return dfs(adj, 0, visited);
}