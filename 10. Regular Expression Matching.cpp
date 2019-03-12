class Solution
{
    bool dp[1004][1004], vis[1004][1004];
    bool call(int i, int j, string &s, string &p)
    {
        if (i == s.size() && j == p.size())
            return 1;
        if (j >= p.size())
            return 0;

        bool &ret = dp[i][j];
        if (vis[i][j])
            return ret;
        vis[i][j] = 1;

        if (i < s.size() && s[i] == p[j])
        {
            ret = ret || call(i + 1, j + 1, s, p);
        }
        if (i < s.size() && p[j] == '.')
        {
            ret = ret || call(i + 1, j + 1, s, p);
        }
        if (p[j] == '*')
        {
            ret = call(i, j + 1, s, p);
            if (i < s.size() && (p[j - 1] == s[i] || p[j - 1] == '.'))
            {
                ret = ret || call(i + 1, j, s, p);
                ret = ret || call(i + 1, j + 1, s, p);
            }
        }
        if (j < p.size() && p[j + 1] == '*')
            ret = ret || call(i, j + 2, s, p);

        return ret;
    }

  public:
    bool isMatch(string s, string p)
    {
        memset(vis, 0, sizeof vis);
        return call(0, 0, s, p);
    }
};