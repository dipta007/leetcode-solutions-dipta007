class Solution {
public:
    vector <int> inp;
    int dp[20][2][2][20];
    int call(int in, int isSmall, int isStart, int v) {
        if(in >= inp.size()) return v;
        int &ret = dp[in][isSmall][isStart][v];
        if(ret != -1) return ret;
        
        int endd = inp[in];
        if(isSmall) endd = 9;
        
        ret = 0;
        if(isStart) {
            for(int i=0; i<=endd; i++) {
                ret += call(in+1, isSmall || i < inp[in], isStart, v + (i==1));
            }    
        }
        else {
            for(int i=1; i<=endd; i++) {
                ret += call(in+1, isSmall || i < inp[in], 1, v + (i==1));
            }
            ret += call(in+1, 1, isStart, v);
        }
        return ret;
    }
    int countDigitOne(int n) {
        inp.clear();
        while(n) {
            inp.push_back(n%10);
            n/=10;
        }
        reverse(inp.begin(), inp.end());
        
        memset(dp, -1, sizeof dp);
        return call(0, 0, 0, 0);
    }
};