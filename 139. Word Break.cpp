class Solution {
public:
    int dp[100004];
    int call(int in, string &st, vector<string>& wordDict) {
        // cout << in << endl;
        if(in >= st.size()) return 1;
        
        int &ret = dp[in];
        if(ret != -1) return ret;
        
        ret = 0;
        for(int i=0; i<wordDict.size(); i++) {
            // cout << st.substr(in, wordDict[i].size()) << endl;
            if(st.substr(in, wordDict[i].size()) == wordDict[i]) {
                ret = ret || call(in + wordDict[i].size(), st, wordDict);
                if(ret) return ret;
            }
        }
        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        return call(0, s, wordDict);
    }
};