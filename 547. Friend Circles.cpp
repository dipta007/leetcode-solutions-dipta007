class Solution
{
  int vis[204];
  void dfs(int u, vector<vector<int>> &M)
  {
    vis[u] = 1;
    for (int i = 0; i < M[u].size(); i++)
    {
      if (M[u][i] == 1)
      {
        if (vis[i] == 0)
          dfs(i, M);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &M)
  {
    int cnt = 0;
    memset(vis, 0, sizeof vis);

    for (int i = 0; i < M.size(); i++)
    {
      if (vis[i] == 0)
      {
        dfs(i, M);
        cnt++;
      }
    }

    return cnt;
  }
};