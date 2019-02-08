class Solution {
public:
    int get(string &s, int &i) {
        int x = 0;
        while(i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
            int kk = s[i] - '0';
            x = x*10 + kk;
            i++;
        }
        return x;
    }
    int calculate(string s) {
        int res = 0;
        int flg = 1;
        int last = 1;
        
        s = "(" + s + ")";
        stack <int> st, op;
        
        for(int i=0; i<s.size(); i++) {
            // cout << s[i] << endl;
            if(s[i] == ' ') continue;
            if(s[i] == '(') {
                st.push(INT_MIN);
                op.push(1);
            }
            else if(s[i] == ')') {
                int now = 0; 
                while(st.size() > 0 && st.top() != INT_MIN) {
                    int kk = st.top(); st.pop();
                    int o = op.top(); op.pop();
                    
                    // cout << kk << " " << o << " " << now << endl;
                    if(o > 0) now += kk;
                    else now -= kk;
                    // cout << kk << " " << o << " " << now << endl;
                }
                st.pop();
                
                
                st.push(now);
            }
            else if(s[i] == '+') {
                op.push(1);
            }
            else if(s[i] == '-') {
                op.push(-1);
            }
            else {
                int val = get(s, i);
                // cout << "a " << val << endl;
                st.push(val);
                i--;
            }
        }
        
        return st.top();
    }
};