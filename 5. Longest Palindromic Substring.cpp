int dp[1004][1004];

class Solution {
public:
    int call(int i, int j, string &st)
    {
        if(i >= j) return 1;
        
        int &ret = dp[i][j];
        if(ret!=-1) return ret;
        
        ret = 0;
        if(st[i]==st[j]) ret = ret || call(i+1, j-1, st);
        
        return ret;
    }

    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        int len = s.size()-1;
        memset(dp, -1, sizeof dp);
        int maxy  = 0, a;
        for(int i=0; i<=len; i++)
        {
            for(int j=i; j<=len; j++)
            {
                // cout << i << " " << j << " " << call(i,j,s) << endl;
                // memset(dp, -1, sizeof dp);
                if(call(i, j, s))
                {
                    if(j-i+1 > maxy)
                    {
                        maxy = j-i+1;
                        a = i;
                    }
                }
            }
        }
        // cout << maxy << endl;
        return s.substr(a, maxy);
    }
};