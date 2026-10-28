/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) return root;

    struct TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;   // p and q are on different sides, so this is the LCA
    return left ? left : right;       // otherwise pass up whichever side found something
}