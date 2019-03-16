class Solution
{
  public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < wall.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < wall[i].size(); j++)
            {
                sum += wall[i][j];
                if (j < wall[i].size() - 1)
                    mp[sum]++;
            }
        }

        int mx = 0;
        for (auto v : mp)
        {
            mx = max(mx, v.second);
            cout << v.first << " " << v.second << endl;
        }

        return wall.size() - mx;
    }
};