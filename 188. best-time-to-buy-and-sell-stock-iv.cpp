class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(!len) return 0;
        
        if(k >= len/2)
        {
            int res = 0;
            int last = prices[0];
            for(int i=1; i<len; i++)
            {
                if(prices[i] > last)
                {
                    res += prices[i] - last;
                }
                last = prices[i];
            }
            
            return res;
        } 
        int dp[k+4][len+4];
        
        for(int i=0; i<len; i++) dp[0][i] = 0;
        for(int i=0; i<=k; i++) dp[i][0] = 0;
        
        for(int i=1; i<=k; i++)
        {
            int mx = 0-prices[0];
            for(int j=1; j<len; j++)
            {
                int now = dp[i][j-1];
                now = max(now, mx + prices[j]);
                dp[i][j] = now;
                mx = max(mx, dp[i-1][j] - prices[j]);
                
                //cout << i << " " << j << " " << dp[i][j] << " " << prices[j] << " " << mx << endl;
            }
        }
        
        return dp[k][len-1];
    }
};