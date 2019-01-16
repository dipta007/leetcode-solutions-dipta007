int dp[1000004];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0; i<1000002; i++) dp[i] = 10000000;
        dp[0] = 0;
        
        for(int i=0; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                long long kk = (long long)i + coins[j];
                if(kk <= amount)
                    dp[kk] = min(dp[kk], dp[i]+1);
            }
        }
        
        if(dp[amount] >= 10000000) dp[amount] = -1;
        return dp[amount];
    }
};