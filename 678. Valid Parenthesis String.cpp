class Solution
{
  int dp[1004][1004];
  bool call(int in, int now, string &st)
  {
    if (in >= st.size())
    {
      return now == 0;
    }
    int &ret = dp[in][now];
    if (ret != -1)
      return ret;

    ret = 0;
    if (st[in] == '(')
      ret = call(in + 1, now + 1, st);
    else if (st[in] == ')' && now)
      ret = call(in + 1, now - 1, st);
    else if (st[in] == '*')
    {
      ret = ret || call(in + 1, now, st);
      ret = ret || call(in + 1, now + 1, st);
      if (now)
        ret = ret || call(in + 1, now - 1, st);
    }

    return ret;
  }

public:
  bool checkValidString(string s)
  {
    memset(dp, -1, sizeof dp);
    return call(0, 0, s);
  }
};