int dp[104][104][104];
class Solution {
public:
    
    int call(string s, int beg, int end, int carry)
    {
        if(beg > end) return 0;
        
        int &ret = dp[beg][end][carry];
        if(ret!=-1) return ret;
        
        ret = 1 + call(s, beg+1, end, 0);
        for(int i=beg+1; i<=end; i++)
        {
            if(s[i]==s[beg])
            {
                int now = call(s, i, end, carry + 1);
                int prev = call(s, beg+1, i-1, 0);
                ret = min(ret, now + prev);
            }
        }
        return ret;
    }
    
    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        return call(s, 0, s.size()-1, 0);
    }
};