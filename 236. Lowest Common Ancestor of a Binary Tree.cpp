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
    bool call(TreeNode *curr, TreeNode *p, TreeNode *q)
    {
        if (!curr)
            return false;

        int lft = call(curr->left, p, q);
        int rgt = call(curr->right, p, q);
        int now = curr == p || curr == q;

        if ((lft && rgt) || (lft && now) || (rgt && now))
        {
            res = curr;
        }
        return lft || rgt || now;
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        res = NULL;
        call(root, p, q);
        return res;
    }
};