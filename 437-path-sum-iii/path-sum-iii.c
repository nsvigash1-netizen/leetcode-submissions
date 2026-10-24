/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static int target;

static int dfs(struct TreeNode *node, long long* path, int depth) {
    if (!node) return 0;
    path[depth] = node->val;

    int count = 0;
    long long sum = 0;

    for (int i = depth; i >= 0; i--) {
        sum += path[i];
        if (sum == target) {
            count++;
        }
    }

    return count + dfs(node->left, path, depth + 1) 
                + dfs(node->right, path, depth + 1);

}
int pathSum(struct TreeNode* root, int targetSum) {
    if (!root) return 0;
    target = targetSum;

    long long *path = malloc(2001 * sizeof(long long));
    int result = dfs(root, path, 0);
    free(path);
    return result;
}