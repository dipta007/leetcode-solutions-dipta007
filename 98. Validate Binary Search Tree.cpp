/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    bool call(TreeNode *root, long l, long r)
    {
        if (!root)
            return 1;

        if (root->val < l || root->val > r)
            return 0;

        int ret = 1;
        ret = ret && call(root->left, l, (long)root->val - 1);
        ret = ret && call(root->right, (long)root->val + 1, r);

        return ret;
    }
    bool isValidBST(TreeNode *root)
    {
        return call(root, (long)INT_MIN - 10, (long)INT_MAX + 10);
    }
};