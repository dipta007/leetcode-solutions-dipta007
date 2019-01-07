class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string &s, int &i) {
        string res = "";
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i])) {
                res += s[i];
                i++;
            }
            else {
                int n = 0;
                while(s[i] != '[') {
                    n = n*10 + (s[i] - '0');
                    i++;
                }
                
                i++;
                string mid = decode(s, i);
                i++;
                
                while(n--) 
                    res += mid;
            }
        }
        return res;
    }
};