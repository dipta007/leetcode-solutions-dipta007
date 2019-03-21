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
    int preIn = 0;
    TreeNode *call(int inS, int inE, vector<int> &preorder, vector<int> &inorder)
    {
        if (preIn >= preorder.size())
            return NULL;
        if (inS > inE)
            return NULL;

        TreeNode *tmp = new TreeNode(preorder[preIn]);

        int now = -1;
        for (int i = inS; i <= inE; i++)
        {
            if (inorder[i] == preorder[preIn])
            {
                now = i;
                break;
            }
        }

        preIn++;

        if (inS >= inE)
            return tmp;

        tmp->left = call(inS, now - 1, preorder, inorder);
        tmp->right = call(now + 1, inE, preorder, inorder);

        return tmp;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        preIn = 0;
        return call(0, inorder.size() - 1, preorder, inorder);
    }
};