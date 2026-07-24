/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getLeaves(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        arr[*idx] = root->val;
        (*idx)++;
        return;
    }
    getLeaves(root->left, arr, idx);
    getLeaves(root->right, arr, idx);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[200], leaves2[200];
    int idx1 = 0, idx2 = 0;
    
    getLeaves(root1, leaves1, &idx1);
    getLeaves(root2, leaves2, &idx2);
    
    if (idx1 != idx2) return false;
    
    for (int i = 0; i < idx1; i++) {
        if (leaves1[i] != leaves2[i]) return false;
    }
    
    return true;
}
