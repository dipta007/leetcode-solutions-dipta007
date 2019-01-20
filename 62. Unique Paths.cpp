class Solution {
public:
    long long dp[104][104];
    long long call(int n, int r) {
        if(r == 1) return n;
        if(n==r) return 1;
        if(r == 0) return 1;
        
        long long &ret = dp[n][r];
        if(ret != -1) return ret;
        
        ret = 0;
        ret += call(n-1, r);
        ret += call(n-1, r-1);
        
        return ret;
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        int kk = (m+n-2);
        int down = m-1;
        return call(kk, down);
    }
};