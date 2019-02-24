class Solution {
    string get(string &st) {
        string tmp = "";
        for(int i=0; i<(int)st.size(); i++) {
            if(i+2 < st.size() && st[i] == st[i+1] && st[i+1] == st[i+2]) {
                int tt = i;
                while(st[i] == st[tt]) i++;
                i--;
            }
            else tmp += st[i];
        }
        return st.size() == tmp.size() ? tmp : get(tmp);
    } 
public:
    int get(string st, string h) {
        st = get(st);
        if(st.size() == 0) return 0;
        if(h.size() == 0) return 10000;
        
        
        int ret = 10000;
        for(int i=0; i<h.size(); i++) {
            string hh = h.substr(0, i) + h.substr(i+1);
            
            string lft = "";
            for(int j=0; j<st.size(); j++) {
                if(st[j] != h[i]) continue;
                ret = min(ret, 1 + get(st.substr(0, j) + h[i] + st.substr(j), hh));
                
                int tt = j;
                while(st[j] == st[tt]) j++;
                j--;
            }
        }
        return ret;
    }
    int findMinStep(string board, string hand) {
        int res = get(board, hand);
        if(res >= 10000) res = -1;
        cout << res << endl;
        return res;
    }
};