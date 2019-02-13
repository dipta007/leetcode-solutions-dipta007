int dp[1004][1004];
int vis[1004][1004];
class Solution {
public:
    int call(int x, int y, vector<vector<int>>& dungeon) {
        if(x == dungeon.size()-1 && y == dungeon[x].size()-1) {
            return max(-dungeon[x][y], 0);
        }
        if(x >= dungeon.size() || y >= dungeon[x].size()) {
            return 10000000;
        }
        
        int &ret = dp[x][y];
        if(vis[x][y]) return ret;
        vis[x][y] = 1;
        
        ret = 10000000;
        ret = min(ret, - dungeon[x][y] + call(x+1, y, dungeon));
        ret = min(ret, - dungeon[x][y] + call(x, y+1, dungeon));
        ret = max(ret, 0);
        
        return ret;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(vis, 0, sizeof vis);
        return call(0, 0, dungeon) + 1;
    }
};