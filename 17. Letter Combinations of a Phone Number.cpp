string st[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    void call(int in, string &digits, vector<string> &res, string now) {
        if(in >= digits.size()) {
            if(now.size()) res.push_back(now);
            return;
        }
        int kk = digits[in] - '0';
        for(int i=0; i<st[kk].size(); i++) {
            call(in+1, digits, res, now+st[kk][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> res;
        string val = "";
        call(0, digits, res, val);
        return res;
    }
};