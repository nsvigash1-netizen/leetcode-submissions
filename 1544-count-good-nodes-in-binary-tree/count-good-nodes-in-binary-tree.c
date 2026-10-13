// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// static int dfs(struct TreeNode *node, int maxSoFar) {
//     if (!node) return 0;
//     int count = 0;
//     if (node->val >= maxSoFar) {
//         count = 1;
//         maxSoFar = node->val;
//     }
//     return count + dfs(node->left, maxSoFar) + dfs(node->right, maxSoFar);
// }
int maxSoFar = INT_MIN;
int goodNodes(struct TreeNode *root) {
    // if (!root) return 0;
    // return dfs(root, root->val);
    if (!root) return 0;
    int saved = maxSoFar, count = 0;
    if (root->val >= maxSoFar) {
        count = 1;
        maxSoFar = root->val;
    }
    int total = count + goodNodes(root->left) + goodNodes(root->right);
    maxSoFar = saved;
    return total;
}