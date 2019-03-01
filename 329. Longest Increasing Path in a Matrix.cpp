int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution
{
    int dp[1004][1004];
    int call(int r, int c, vector<vector<int>> &m)
    {
        int &ret = dp[r][c];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];

            if (x >= 0 && y >= 0 && x < m.size() && y < m[x].size() && m[x][y] > m[r][c])
            {
                ret = max(ret, 1 + call(x, y, m));
            }
        }
        return ret;
    }

  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        memset(dp, -1, sizeof dp);
        int ret = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (dp[i][j] == -1)
                {
                    ret = max(ret, call(i, j, matrix));
                }
            }
        }
        return ret + 1;
    }
};