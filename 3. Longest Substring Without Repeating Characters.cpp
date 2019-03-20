class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        string st = s;

        int len = 0;
        unordered_map<char, int> mp;

        int low = 0;
        for (int high = 0; high < s.size(); high++)
        {
            mp[st[high]]++;

            while (mp[st[high]] > 1)
            {
                mp[st[low]]--;
                low++;
            }

            len = max(len, high - low + 1);
        }

        return len;
    }
};