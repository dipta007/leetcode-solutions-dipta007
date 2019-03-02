class Solution
{
  public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;
        int unq = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (mp[t[i]] == 0)
                unq++;
            mp[t[i]]++;
        }

        int low = 0;
        string res = "";

        if (unq == 0)
            return res;
        unordered_map<char, int> mp1;
        int rl;
        int len = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            mp1[s[i]]++;
            if (mp[s[i]] && mp1[s[i]] == mp[s[i]])
                cnt++;

            while (cnt == unq && low <= i)
            {
                // cout << low << " " << i << " " << cnt << endl;
                if (i - low + 1 < len)
                {
                    len = i - low + 1;
                    rl = low;
                }

                if (mp[s[low]] && mp1[s[low]] == mp[s[low]])
                    cnt--;
                mp1[s[low]]--;
                low++;
            }
        }

        if (len == INT_MAX)
            return "";
        return s.substr(rl, len);
    }
};