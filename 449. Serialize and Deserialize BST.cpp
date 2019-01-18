/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void serial(TreeNode* curr, string &st) {
        st += to_string(curr->val) + ",";
        
        if(!curr->left) st += "N,";
        else serial(curr->left, st);
        
        if(!curr->right) st += "N,";
        else serial(curr->right, st);
    }
    
    void deserial(int &in, string &st, TreeNode* curr) {
        int x = 0;
        while(st[in] != ',') x = x*10 + (st[in] - '0'), in++;
        in++;
        curr->val = x;
        // cout << x << endl;
        
        if(st[in] != 'N') {
            curr->left = new TreeNode(0);
            deserial(in, st, curr->left);
        }
        else in+=2;
        
        if(st[in] != 'N') {
            curr->right = new TreeNode(0);
            deserial(in, st, curr->right);
        }
        else in+=2;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ret = "";
        serial(root, ret);
        cout << ret << endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        TreeNode *root = new TreeNode(0);
        int v = 0;
        deserial(v, data, root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));