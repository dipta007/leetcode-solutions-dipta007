class Solution {
    int vis[30][30][104];
    double dp[30][30][104];
    int dx[8] = {-1, -2, -2, -1, 1, 2,  2,  1};
    int dy[8] = {-2, -1,  1,  2, 2, 1, -1, -2};
public:
    double call(int r, int c, int k, int n) {
        if(r < 0 || r >= n || c < 0 || c >= n) return 0;
        if(k == 0) return 1;
        
        double &ret = dp[r][c][k];
        if(vis[r][c][k]) return ret;
        vis[r][c][k] = 1;
        
        double res = 0;
        for(int i=0; i<8; i++) {
            int x = r + dx[i];
            int y = c + dy[i];
            
            res += call(x, y, k-1, n) * (1.0/8.0);
        }
        
        return ret = res;
    }
    double knightProbability(int N, int K, int r, int c) {
        memset(vis, 0, sizeof vis);
        return call(r, c, K, N);
    }
};