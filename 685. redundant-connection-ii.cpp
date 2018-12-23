class Solution {
    int par[2004];
    int rank[2004];
    
    int find(int i) {
        // cout << i << " " << par[i] << endl;
        if(par[i] != i)
            return par[i] = find(par[i]);
        return par[i];
    }
    
    bool unionn(int x, int y) {
        // cout << x << " " << y << endl;
        int xr = find(x);
        int yr = find(y);
        
        // cout << x << " " << y << " " << xr << " " << yr << endl;
        
        if(xr == yr) return false;
        
        if(rank[xr] < rank[yr]) {
            par[xr] = yr;
        }
        else if(rank[yr] < rank[xr]) {
            par[yr] = xr;
        }
        else {
            par[xr] = yr;
            rank[yr]++;
        }
        return true;
    }
    
    vector <vector<int>> adj;
    int vis[1004];
    void dfs(int u, int par) {
        vis[u] = 1;
        for(auto v: adj[u]) {
            if(vis[v] == 0) {
                dfs(v, u);
            }
        }
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int flg = 1;
        vector < int > faulty;
        
        for(int i=0; i<=1000; i++) {
            par[i] = i;
        }
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(par[v] == v) {
                par[v] = u;
            }
            else {
                faulty.push_back(par[v]);
                faulty.push_back(v);
                faulty.push_back(u);
                faulty.push_back(v);
                
                flg = 2;
                break;
            }
        }
        
        cout << flg << endl;
        // for(auto v: faulty) {
        //     cout << v << endl;
        // }
        
        vector < int > res;
        if(flg == 1) {
            for(int i=0; i<=1000; i++) {
                par[i] = i;
                rank[i] = 0;
            }
            for(int i=0; i<edges.size(); i+=1) {
                if(unionn(edges[i][0], edges[i][1]) == false) {
                    res.push_back(edges[i][0]);
                    res.push_back(edges[i][1]);
                }
            }    
        }
        else {
            adj.assign(edges.size()+4, vector <int> ());
            for(int i=0; i<edges.size(); i++) {
                int x = edges[i][0];
                int y = edges[i][1];
                if(faulty[2] == x && faulty[3] == y) continue;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            
            res.push_back(faulty[2]);
            res.push_back(faulty[3]);
            
            dfs(1, -1);
            for(int i=2; i<=edges.size(); i++) {
                if(vis[i] == 0) {
                    res.clear();
                    res.push_back(faulty[0]);
                    res.push_back(faulty[1]);
                }
            }
        }
        
        
        return res;
    }
};