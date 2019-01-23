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
    int k;
    TreeNode *target;
    vector <int> res;
public:
    int dfs(TreeNode *curr) {
        if(!curr) return -1;
        
        if(curr == target) {
            add(curr, 0);
            return 1;
        }
        
        int l = dfs(curr->left);
        int r = dfs(curr->right);
        if(l != -1) {
            if(l==k) add(curr, k);
            add(curr->right, l+1);
            return l+1;
        }
        else if(r != -1) {
            if(r==k) add(curr, k);
            add(curr->left, r+1);
            return r+1;
        }
        return -1;
    }
    
    void add(TreeNode *curr, int dist) {
        if(!curr) return;
        // cout << curr->val << " " << dist << endl;
        
        if(dist == k) {
            res.push_back(curr->val);
        }
        else {
            add(curr->left, dist+1);
            add(curr->right, dist+1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        k = K;
        this->target = target;
        res.clear();
        
        if(!root) return res;
        dfs(root);
        return res;
    }
};