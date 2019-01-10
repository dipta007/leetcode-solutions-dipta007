class Solution {
public:
    vector < vector <int> > adj;
    int vis[10004];
    int dfs(int u) {
        vis[u] = 1;
        int ret = 1;
        for(int v: adj[u]) {
            if(vis[v] == 0) {
                ret += dfs(v);
            }
        }
        return ret;
    }
    int removeStones(vector<vector<int>>& stones) {
        adj.assign(10004, vector<int> ());
        
        for(int i=0; i<stones.size(); i++) {
            for(int j=i+1; j<stones.size(); j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        memset(vis, 0, sizeof vis);
        int res = 0;
        for(int i=0; i<=10000; i++) {
            if(vis[i] == 0) {
                res += (dfs(i) - 1);
            }
        }
        return res;
    }
};