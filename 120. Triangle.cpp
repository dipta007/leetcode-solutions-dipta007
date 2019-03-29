class Solution
{
  int dp[1004][1004];
  int call(int r, int c, vector<vector<int>> &tri)
  {
    if (r >= tri.size())
      return 0;

    int &ret = dp[r][c];
    if (ret != -1)
      return ret;

    ret = INT_MAX;
    ret = min(ret, tri[r][c] + call(r + 1, c, tri));
    ret = min(ret, tri[r][c] + call(r + 1, c + 1, tri));

    return ret;
  }

public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    memset(dp, -1, sizeof dp);
    return call(0, 0, triangle);
  }
};