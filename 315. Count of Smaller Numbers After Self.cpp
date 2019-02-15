int tree[800004];
class Solution {
    void update(int node, int b, int e, int i) {
        if(b == i && e == i) {
            // cout << i << endl;
            tree[node]++;
            return;
        }
        if(e < i || b > i) return;
        
        int left = node << 1;
        int right = left + 1;
        int mid = (b + e) >> 1;
        
        update(left, b, mid, i);
        update(right, mid+1, e, i);
        
        tree[node] = tree[left] + tree[right];
    }
    
    int query(int node, int b, int e, int i, int j) {
        // cout << b << " " << e << " " << tree[node] << endl;
        if(e < i || b > j) return 0;
        if(b >= i && e <= j) return tree[node];
        
        int left = node << 1;
        int right = left + 1;
        int mid = (b + e) >> 1;
        
        int p1 = query(left, b, mid, i, j);
        int p2 = query(right, mid+1, e, i, j);
        return p1+p2;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        memset(tree, 0, sizeof tree);
        vector <int> ret(nums.size());
        
        for(int i=nums.size()-1; i>=0; i--) {
            int kk = nums[i] + 100000;
            // cout << kk << endl;
            ret[i] = query(1, 0, 200000, 0, kk-1);
            update(1, 0, 200000, kk);
        }
        return ret;
    }
};