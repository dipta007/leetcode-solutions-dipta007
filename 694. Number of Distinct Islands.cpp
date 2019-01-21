int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
class Solution {
public:
    int vis[54][54];
    void dfs(int r, int c, string &st, vector<vector<int>>& grid, int now) {
        st += (char) (now + '0');
        
        vis[r][c] = 1;
        for(int i=0; i<4; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && vis[x][y] == 0 && grid[x][y] == 1) {
                dfs(x, y, st, grid, i+1);
            }
        }
        st += '0';
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof vis);
        unordered_map <string, int> mp;
        int cnt = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) {
                    string tmp = "";
                    dfs(i, j, tmp, grid, 0);
                    if(mp[tmp] == 0) cnt++;
                    mp[tmp] = 1;
                } 
            }
        }
        return cnt;
    }
};