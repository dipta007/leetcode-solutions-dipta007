int dx[] = {0, 1, 1, 1};
int dy[] = {1, 0, 1, -1};

vector < vector < vector <int> > > vis;

class Solution {
    int dfs(int i, int j, int k, vector<vector<int>>& M) {
        vis[i][j][k] = 1;
        int x = i + dx[k];
        int y = j + dy[k];
        
        int ret = 1;
        if(x >= 0 && y >= 0 && x<M.size() && y<M[x].size() && M[x][y] == 1 && vis[x][y][k] == 0) {
            ret += dfs(x, y, k, M);
        }
        return ret;
    }
public:
    int longestLine(vector<vector<int>>& M) {
        vis.assign(M.size(), vector<vector<int>> ());
        for(int i=0; i<vis.size(); i++) {
            vis[i].assign(M[i].size(), vector<int>());
            for(int j=0; j<vis[i].size(); j++) {
                vis[i][j].assign(4, 0);
            }
        }
        int mx = 0;
        for(int i=0; i<M.size(); i++) {
            for(int j=0; j<M[i].size(); j++) {
                for(int k=0; k<4; k++) {
                    if(vis[i][j][k] == 0 && M[i][j] == 1) {
                        int kk = dfs(i, j, k, M);
                        mx = max(mx, kk);
                    }
                }         
            }
        }
        return mx;
    }
};