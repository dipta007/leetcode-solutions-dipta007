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
    Node *lvlTN[104];

    void call(Node *curr, int lvl)
    {
        if (!curr)
            return;
        curr->next = lvlTN[lvl];

        lvlTN[lvl] = curr;
        call(curr->right, lvl + 1);
        call(curr->left, lvl + 1);
    }

  public:
    Node *connect(Node *root)
    {
        call(root, 0);
        return root;
    }
};