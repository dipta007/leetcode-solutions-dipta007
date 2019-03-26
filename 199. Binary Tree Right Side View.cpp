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
    vector<int> ret;
    void call(TreeNode *curr, int lvl)
    {
        if (!curr)
            return;

        if (lvl > ret.size())
            ret.push_back(curr->val);

        call(curr->right, lvl + 1);
        call(curr->left, lvl + 1);
    }

  public:
    vector<int> rightSideView(TreeNode *root)
    {
        call(root, 1);
        return ret;
    }
};