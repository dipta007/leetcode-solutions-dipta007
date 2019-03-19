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
    TreeNode *res;

    void call(TreeNode *curr)
    {
        if (!curr)
            return;

        res->right = new TreeNode(curr->val);
        res = res->right;

        call(curr->left);
        call(curr->right);
    }

  public:
    void flatten(TreeNode *root)
    {
        if (root)
        {
            res = new TreeNode(0);
            TreeNode *ret = res;
            call(root);
            *root = *(ret->right);
        }
    }
};