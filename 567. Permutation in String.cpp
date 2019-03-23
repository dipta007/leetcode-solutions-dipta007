class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false;

        int mp[30], nmp[30];
        memset(mp, 0, sizeof mp);
        memset(nmp, 0, sizeof nmp);
        for (int i = 0; i < s1.size(); i++)
        {
            mp[s1[i] - 'a']++;
            nmp[s2[i] - 'a']++;
        }

        if (check(mp, nmp))
            return true;

        for (int i = s1.size(); i < s2.size(); i++)
        {
            nmp[s2[i] - 'a']++;
            nmp[s2[i - s1.size()] - 'a']--;

            if (check(mp, nmp))
                return true;
        }

        return false;
    }

    bool check(int a[], int b[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};