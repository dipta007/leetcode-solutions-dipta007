class Solution
{
    vector<int> res;
    vector<vector<int>> adj;
    unordered_map<int, int> rev, mp;
    void dfs(int u, int p)
    {
        res.push_back(rev[u]);

        for (auto v : adj[u])
        {
            if (v != p)
                dfs(v, u);
        }
    }

  public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        adj.assign(pid.size() + 4, vector<int>());

        mp[0] = pid.size();
        for (int i = 0; i < pid.size(); i++)
        {
            rev[i] = pid[i];
            mp[pid[i]] = i;
        }

        for (int i = 0; i < ppid.size(); i++)
        {
            adj[mp[ppid[i]]].push_back(i);
        }

        dfs(mp[kill], mp[ppid[mp[kill]]]);

        return res;
    }
};