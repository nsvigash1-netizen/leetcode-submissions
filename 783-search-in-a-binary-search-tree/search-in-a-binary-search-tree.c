/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// void dfs(struct TreeNode* node, int val, struct TreeNode* answer) {
//     if (!node) return NULL;
//     if (node->val == val) return node;
// }
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) {
        return root;
    }
    struct TreeNode* left = searchBST(root->left, val);
    struct TreeNode* right = searchBST(root->right, val);
    return left ? left : right;  
}