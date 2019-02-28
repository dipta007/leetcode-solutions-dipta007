class Solution {
public:
    bool check(string &a, string &b, int ind) {
        for(int i=0;ind <a.size() && i<b.size(); i++) {
            if(a[ind] != b[i]) return false;
            ind++;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        string r = s;
        string st = s;
        reverse(r.begin(), r.end());
        for(int i=0; i<r.size(); i++) {
            if(check(r, st, i)) {
                return r.substr(0, i) + s;
            }
        }
        return r;
    }
};