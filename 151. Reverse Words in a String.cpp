class Solution {
public:
    string reverseWords(string s) {
        vector<string> vs;
        string now = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                if(now.size()) {
                    vs.push_back(now);
                }
                now = "";
            }
            else now += s[i];
        }
        if(now.size()) {
            vs.push_back(now);
        }
        
        s = "";
        for(int i=vs.size()-1; i>=0 ;i--) {
            if(i != vs.size() - 1) {
                s += " ";
            }
            s += vs[i];  
        }
        
        return s;
    }
};