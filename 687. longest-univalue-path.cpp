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
    int res = 0;
    int dfs(TreeNode* curr) {
        if(curr == NULL) return 0;
        int now = 1, lft = 0, rgt = 0;
        if(curr->left && curr->left->val == curr->val) {
            lft += dfs(curr->left);
        }
        else dfs(curr->left);
        
        if(curr->right && curr->right->val == curr->val) {
            rgt += dfs(curr->right);
        }
        else dfs(curr->right);
        res = max(res, now + lft + rgt);
        
        // cout << curr->val << " " << now << endl;
        return max(now+lft, now+rgt);
    }
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfs(root);
        return max(0, res-1);
    }
};