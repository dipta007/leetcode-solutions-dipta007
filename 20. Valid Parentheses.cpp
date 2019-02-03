class Solution {
public:
    bool isValid(string st) {
        stack <char> s;
        bool flg = 1;
        for(int i=0; i<st.size() && flg; i++) {
            if(st[i] == ')') {
                if(s.size() == 0) flg = 0;
                else {
                    if(s.top() != '(') flg = 0;
                    else s.pop();
                }
            }
            else if(st[i] == '}') {
                if(s.size() == 0) flg = 0;
                else {
                    if(s.top() != '{') flg = 0;
                    else s.pop();
                }
            }
            else if(st[i] == ']') {
                // cout << s.top() << endl;
                if(s.size() == 0) flg = 0;
                else {
                    if(s.top() != '[') flg = 0;
                    else s.pop();
                }
            }
            else {
                s.push(st[i]);
            }
        }
        if(s.size()) flg = 0;
        return flg;
    }
};