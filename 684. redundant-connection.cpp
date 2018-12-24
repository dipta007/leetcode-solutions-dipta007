class Solution {
    int par[1004];
    int rank[1004];
    
    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    
    bool unionn(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        
        if(xr == yr) return false;
        
        if(rank[xr] < rank[yr]) {
            par[xr] = yr;
        }
        else if(rank[xr] > rank[yr]) {
            par[yr] = xr;
        }
        else {
            par[xr] = yr;
            rank[yr]++;
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0; i<=1000; i++) {
            par[i] = i;
            rank[i] = 0;
        }
        vector <int> res;
        for(int i=0; i<edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            
            if(unionn(x, y) == false) {
                res.push_back(x);
                res.push_back(y);
                break;
            } 
        }
        return res;
    }
};