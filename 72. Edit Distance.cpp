class Solution {
public:
    int dp[1004][1004];
    int call(int i, int j, string &w1, string &w2) {
        if(i >= w1.size()) return (int)w2.size() - j;
        if(j >= w2.size()) return (int)w1.size() - i;
        
        int &ret = dp[i][j];
        if(ret != -1) return ret;
        
        ret = 100000;
        if(w1[i] == w2[j]) {
            ret = min(ret, call(i+1, j+1, w1, w2));
        }
        else {
            ret = min(ret, 1 + call(i, j+1, w1, w2));
            ret = min(ret, 1 + call(i+1, j, w1, w2));
            ret = min(ret, 1 + call(i+1, j+1, w1, w2));
        }
        return ret;
    }
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof dp);
        return call(0, 0, word1, word2);
    }
};