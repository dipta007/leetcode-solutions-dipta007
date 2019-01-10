/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode *curr) {
        if(!curr) return 0;
        int ret = 1;
        
        ret += dfs(curr->left);
        ret += dfs(curr->right);
        
        return ret;
    }
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};