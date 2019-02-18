#define ff first
#define ss second
class Solution {
    bool canBe(string &word, string &now) {
        vector < pair<char, int> > v1, v2;
        
        int cnt = 1;
        for(int i=1; i<word.size(); i++) {
            if(word[i] == word[i-1]) {
                cnt++;
            }
            else {
                v1.push_back(make_pair(word[i-1], cnt));
                cnt=1;
            }
        }
        v1.push_back(make_pair(word.back(), cnt));
        
        cnt = 1;
        for(int i=1; i<now.size(); i++) {
            if(now[i] == now[i-1]) {
                cnt++;
            }
            else {
                v2.push_back(make_pair(now[i-1], cnt));
                cnt=1;
            }
        }
        v2.push_back(make_pair(now.back(), cnt));
        
        if(v1.size() != v2.size()) return false;
        
        for(int i=0; i<v1.size(); i++) {
            if(v1[i].ff != v2[i].ff) return false;
            if(v1[i].ss == 2 && v2[i].ss != 2) return false;
            if(v2[i].ss > v1[i].ss) return false;
        }
        return true;
    }
public:
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;
        for(auto &st: words) {
            if(canBe(S, st))
                cnt++;
        }
        return cnt;
    }
};