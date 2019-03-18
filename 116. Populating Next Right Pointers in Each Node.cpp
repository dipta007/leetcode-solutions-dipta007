/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution
{
    Node *lvl[104];

    void call(Node *curr, int l)
    {
        if (!curr)
            return;
        curr->next = NULL;
        if (lvl[l])
        {
            lvl[l]->next = curr;
        }
        lvl[l] = curr;

        call(curr->left, l + 1);
        call(curr->right, l + 1);
    }

  public:
    Node *connect(Node *root)
    {
        for (int i = 0; i < 101; i++)
            lvl[i] = NULL;
        call(root, 0);

        return root;
    }
};