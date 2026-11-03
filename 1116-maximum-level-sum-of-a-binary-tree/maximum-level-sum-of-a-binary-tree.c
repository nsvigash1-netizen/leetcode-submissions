/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxLevelSum(struct TreeNode* root) {
    if (!root) return 0;
    struct TreeNode** queue = malloc(10000 * sizeof(struct TreeNode*));

    int head = 0, tail = 0;
    int maxSum = INT_MIN, maxLevel = 0, curLevel = 0;

    queue[tail++] = root;
    while(head < tail) {
        int levelSize = tail - head;
        int curSum = 0;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[head++];
            curSum += node->val;
            if (i == levelSize - 1) {
                curLevel++;
                if (curSum > maxSum) {
                    maxSum = curSum;
                    maxLevel = curLevel;                    
                }
            }
            if (node->left) queue[tail++] = node->left;
            if (node->right) queue[tail++] = node->right;
        }
    }
    free(queue);
    return maxLevel;

}