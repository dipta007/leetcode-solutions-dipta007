class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        vector<int> mark(104, INT_MAX);

        vector<int> ret(T.size(), 0);
        for (int i = T.size() - 1; i >= 0; i--)
        {
            int now = INT_MAX;
            for (int j = T[i] + 1; j <= 100; j++)
            {
                if (mark[j] != INT_MAX)
                {
                    now = min(now, mark[j]);
                }
            }
            if (now == INT_MAX)
                now = i;
            ret[i] = (now - i);

            mark[T[i]] = i;
        }

        return ret;
    }
};