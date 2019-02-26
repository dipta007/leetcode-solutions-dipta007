class Solution {
    unordered_set <string> res;
    int dp[1004][1004];
    int find(int in, string &s, int val) {
        int &ret = dp[in][val];
        if(in >= s.size()) {
            if(val == 0) return ret = 0;
            return ret = 100000;
        }
        if(ret != -1) return ret;
        
        ret = 100000;
        if(s[in] == '(') {
            ret = min(ret, find(in+1, s, val+1));
            ret = min(ret, 1 + find(in+1, s, val));
        }
        else if(s[in] == ')') {
            if(val > 0) ret = min(ret, find(in+1, s, val-1));
            ret = min(ret, 1 + find(in+1, s, val));
        }
        else ret = find(in+1, s, val);
        return ret;
    }
    void call(int in, string &s, string now, int val, int ff) {
        if(ff < 0) return;
        if(in >= s.size()) {
            if(val == 0) {
                res.insert(now);
            }
            return;
        }
        
        if(s[in] == '(') {
            if(dp[in+1][val+1] == ff) call(in+1, s, now + s[in], val+1, ff);
            if(dp[in+1][val] == ff-1) call(in+1, s, now, val, ff-1);
        }
        else if(s[in] == ')') {
            if(val > 0 && dp[in+1][val-1] == ff) call(in+1, s, now + s[in], val-1, ff);
            if(dp[in+1][val] == ff-1) call(in+1, s, now, val, ff-1);
        }
        else call(in+1, s, now + s[in], val, ff);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        memset(dp, -1, sizeof dp);
        int kk = find(0, s, 0);
        if(kk >= 10000) return vector<string>(res.begin(), res.end());
        call(0, s, "", 0, kk);
        return vector<string>(res.begin(), res.end());
    }
};