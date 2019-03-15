class Solution
{
  public:
    unordered_map<char, int> mp;
    string frequencySort(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto v : mp)
        {
            pq.push(make_pair(v.second, v.first));
        }

        string res = "";
        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            while (p.first--)
                res += p.second;
        }
        return res;
    }
};