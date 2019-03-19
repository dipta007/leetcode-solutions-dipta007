class Solution
{
  public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }

        for (auto v : mp)
        {
            pq.push(make_pair(-v.second, v.first));
        }

        int kk = k;
        vector<string> ret;
        while (kk-- && !pq.empty())
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
    }
};