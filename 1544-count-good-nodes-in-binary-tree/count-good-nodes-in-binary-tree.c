// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

static int dfs(struct TreeNode *node, int maxSoFar) {
    if (!node) return 0;
    int count = 0;
    if (node->val >= maxSoFar) {
        count = 1;
        maxSoFar = node->val;
    }
    return count + dfs(node->left, maxSoFar) + dfs(node->right, maxSoFar);
}

int goodNodes(struct TreeNode *root) {
    if (!root) return 0;
    return dfs(root, root->val);
}