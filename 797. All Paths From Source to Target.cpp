class Solution
{
    vector<vector<int>> res;
    int dest;
    void call(int u, vector<int> v, vector<vector<int>> &adj)
    {
        if (u == dest)
        {
            v.push_back(u);
            res.push_back(v);
            v.pop_back();
            return;
        }

        v.push_back(u);
        cout << u << endl;
        for (auto vv : adj[u])
        {
            call(vv, v, adj);
        }
        v.pop_back();
    }

  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        if (graph.size() == 0)
            return res;
        vector<int> v;
        dest = graph.size() - 1;
        call(0, v, graph);
        return res;
    }
};