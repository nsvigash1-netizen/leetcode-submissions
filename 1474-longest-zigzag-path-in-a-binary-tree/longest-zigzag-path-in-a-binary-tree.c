/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 // 0 means left, 1 means right
static int best;
static void dfs(struct TreeNode* node, bool goRight, int len) {
    if (!node) {
        return;
    }
    if (len > best)
        best = len;
    if (!goRight) {
        dfs(node->left, 1, len + 1);
        dfs(node->right, 0, 1); //starts a fresh count in the opposite direction
    } else if (goRight) {
        dfs(node->right, 0, len + 1);
        dfs(node->left, 1, 1);
    }
}

int longestZigZag(struct TreeNode* root) {\
    best = 0;
    dfs(root, 0, 0);
    dfs(root, 1, 0);    
    return best;
}