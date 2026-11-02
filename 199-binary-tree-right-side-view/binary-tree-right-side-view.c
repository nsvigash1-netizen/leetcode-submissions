int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;

    // Constraints say up to 100 nodes; adjust if the problem allows more
    struct TreeNode** queue = malloc(100 * sizeof(struct TreeNode*));
    int* result = malloc(100 * sizeof(int));

    int head = 0, tail = 0;
    queue[tail++] = root;

    while (head < tail) {
        int levelSize = tail - head;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];

            // last node in the level -> visible from the right
            if (i == levelSize - 1) {
                result[(*returnSize)++] = node->val;
            }

            if (node->left)  queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
    }

    free(queue);
    return result;
}