class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;

        vector<int> rgt(prices.size(), 0);

        int maxy = prices.back();
        int res = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] >= maxy)
            {
                maxy = prices[i];
            }
            else
            {
                res = max(res, maxy - prices[i]);
            }
            rgt[i] = res;
        }

        int ret = res;
        int mini = prices[0];
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] <= mini)
            {
                mini = prices[i];
            }
            else
            {
                int now = prices[i] - mini + rgt[i + 1];
                ret = max(ret, now);
            }
        }
        return ret;
    }
};