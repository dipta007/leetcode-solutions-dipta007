class Solution {
public:
    string countAndSay(int n) {
        string tmp = "1";
        for(int i=2; i<=n; i++) {
            string now = "";
            for(int j=0; j<tmp.size();) {
                int cnt = 0, k;
                for(k=j; k<tmp.size(); k++) {
                    if(tmp[k] == tmp[j]) {
                        cnt ++;
                    }
                    else {
                        break;
                    }
                }
                
                if(cnt) {
                    char ch = cnt + '0';
                    now += ch;
                    now += tmp[j];
                }
                
                j = k;
                if(k == tmp.size()) {
                    break;
                }
            }
            
            tmp = now;
        }
        return tmp;
    }
};