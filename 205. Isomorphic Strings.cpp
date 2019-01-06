class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        map <char, char> mp, mark;
        int flg = 1;
        for(int i=0; i<s.size(); i++) {
            char a = s[i];
            char b = t[i];
            
            if(mp.find(a) == mp.end() && mark[b] == 0) {
                mp[a] = b;
                mark[b] = 1;
            }
            else if(mp[a] != t[i]) {
                flg = 0;
            }
        }
        return flg;
    }
};