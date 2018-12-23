class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len ==0) return 0;
        
        int lft[len+4], rgt[len+4];
        
        int tmp = prices[0];
        lft[0] = 0;
        for(int i=1; i<len; i++)
        {
            if(prices[i] < tmp)
            {
                lft[i] = lft[i-1];
                tmp = prices[i];
            }
            else
            {
                lft[i] = max(lft[i-1], prices[i] - tmp);
            }
        }
        
        rgt[len-1] = rgt[len] = 0;
        tmp = prices[len-1];
        for(int i=len-2; i>=0; i--)
        {
            if(prices[i] < tmp)
            {
                rgt[i] = max(rgt[i+1], tmp - prices[i]);
            }
            else
            {
                rgt[i] = rgt[i+1];
                tmp = prices[i];
            }
        }
        
        int res = 0;
        for(int i=0; i<len;i++)
        {
            // cout << lft[i] << " " << rgt[i] << endl;
            if(lft[i] + rgt[i+1] > res)
            {
                res = lft[i] + rgt[i+1];
            }
        }
        
        return res;
    }
};