class Solution {
public:
    
    int call(int i, int j, string &s, string &p, vector<vector<int> > & dp)
    {
        //cout << i << " " << j << endl;
        if(i>=s.size())
        {
            for(int k=j; k<p.size(); k++)
            {
                if(p[k]!= '*' && p[k+1]!='*') return false;
            }
            return true;
        }
        if(j>=p.size())
        {
            return false;
        }
        
        //if(dp[i][j]!=-1) return dp[i][j];
        
        int ret = 0;
        if(j <p.size()-1 && p[j+1]=='*')
        {
            ret = ret || call(i, j+2, s, p,dp);
        }
        if(s[i]==p[j])
        {
            ret = ret || call(i+1, j+1, s, p,dp);
        }
        if(p[j]=='.')
        {
            ret = ret || call(i+1, j+1, s, p,dp);
        }
        if(p[j]=='*')
        {
            ret = ret || call(i, j+1, s, p,dp);
            int cnt = i;
            while(cnt < s.size() && (s[cnt]==p[j-1] || p[j-1]=='.') )
            {
                cnt++;
                ret = ret || call(cnt, j+1, s, p,dp);
            }
        }
        
        //cout << i << " " << j << endl;
        return dp[i][j] = ret;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int> > dp(n + 1, vector<int> (m + 1, -1));
        return call(0,0,s,p,dp) == 1;
    }
};