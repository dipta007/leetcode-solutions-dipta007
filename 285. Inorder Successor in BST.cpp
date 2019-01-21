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
    int flg;
    TreeNode *res, *dest;
    
    void inOrder(TreeNode *curr) {
        if(res) return;
        if(!curr) return;
        inOrder(curr->left);
        
        if(flg == 1 && !res) {
            res = curr;
            return;
        }
        if(curr == dest) {
            flg = 1;
        }
        inOrder(curr->right);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        res = NULL;
        flg = 0;
        dest = p;
        inOrder(root);
        if(res) cout << res->val << endl;
        return res;
    }
};