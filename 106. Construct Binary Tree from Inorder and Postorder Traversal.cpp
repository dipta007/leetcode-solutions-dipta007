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
    int post;
    TreeNode *call(int inS, int inE, vector<int> &inorder, vector<int> &postorder)
    {
        if (post < 0 || inS > inE)
            return NULL;

        TreeNode *tmp = new TreeNode(postorder[post]);

        int now = 0;
        for (int i = inS; i <= inE; i++)
        {
            if (inorder[i] == postorder[post])
            {
                now = i;
                break;
            }
        }
        post--;

        if (inS == inE)
            return tmp;

        tmp->right = call(now + 1, inE, inorder, postorder);
        tmp->left = call(inS, now - 1, inorder, postorder);

        return tmp;
    }

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        post = postorder.size() - 1;
        return call(0, inorder.size() - 1, inorder, postorder);
    }
};