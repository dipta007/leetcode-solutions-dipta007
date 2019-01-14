int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution {
public:
    bool vis[1004][1004];
    
    void dfs(int i, int j, vector<vector<char>>& grid) {
        //cout << i << " " << j << endl;
        vis[i][j] = 1;
        for(int k=0; k<4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && y >= 0 && x<grid.size() && y<grid[x].size() && vis[x][y] == 0 && grid[x][y] == '1') {
                dfs(x, y, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(vis[i][j] == 0 && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};