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
    vector < int > res;
    void dfs(TreeNode *curr) {
        if(curr) {
            dfs(curr->left);
            res.push_back(curr->val);
            dfs(curr->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};