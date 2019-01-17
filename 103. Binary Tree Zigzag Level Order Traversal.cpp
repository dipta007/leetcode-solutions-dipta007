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
    vector<vector<int>> ret;
    void dfs(TreeNode *curr, int lvl) {
        if(!curr) return;
        
        vector <int> now;
        if(ret.size() <= lvl) ret.push_back(now);
        
        ret[lvl].push_back(curr->val);
        dfs(curr->left, lvl+1);
        dfs(curr->right, lvl+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        dfs(root, 0);
        for(int i=1; i<ret.size(); i+=2) {
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};