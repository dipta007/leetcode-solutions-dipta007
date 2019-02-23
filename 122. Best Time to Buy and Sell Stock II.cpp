class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int res = 0;
        int last = prices[0];
        
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] < last) {
                last = prices[i];
            }
            else {
                res += prices[i] - last;
                last = prices[i];
            }
        }
        return res;
    }
};