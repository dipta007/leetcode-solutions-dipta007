class Solution {
public:
    int vis[1004][1004], tt;
    bool dp[1004][1004];
    string now, st;
    bool call() {
        int j = 0;
        for(int i=0; i<now.size(); i++) {
            while(j < st.size() && st[j] != now[i]) j++;
            if(j >= st.size()) return false;
            j++;
        }
        return true;
    }
    string findLongestWord(string s, vector<string> d) {
        st = s;
        // sort(d.begin(), d.end(), cmp);
        string res = "";
        for(int i=0; i<d.size(); i++) {
            now = d[i];
            tt = i+1;
            if(d[i].size() > res.size() && call()) {
                res = d[i];
            }
            else if(d[i].size() == res.size() && d[i] < res && call()) {
                res = d[i];
            }
        }
        return res;
    }
};