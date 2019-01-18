int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
public:
    bool vis[1004][1004];
    int dfs(int x, int y, vector<vector<int>> &grid) {
        vis[x][y] = 1;
        int ret = 1; 
        for(int i=0; i<4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X >= 0 && Y >= 0 && X<grid.size() && Y<grid[X].size() && vis[X][Y] == 0 && grid[X][Y] == 1) {
                ret += dfs(X, Y, grid);
            }
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof vis);
        int ret = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    int now = dfs(i, j, grid);
                    ret = max(ret, now);
                }
            }
        }
        return ret;
    }
};