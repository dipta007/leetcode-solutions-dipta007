vector <int> all;
class Solution {
public:
    
    long long sTn(string &st) {
        stringstream ss(st);
        long long x;
        ss >> x;
        return x;
    }
    
    string nTs(long long v) {
        return to_string(v);
    }
    
    bool pal(long long xx) {
        string x = nTs(xx);
        for(int i=0, j=x.size()-1; i<j; i++, j--) {
            if(x[i] != x[j]) return false;
        }
        return true;
    }
    
    bool check(string &st, int &val) {
        long long now = sTn(st);
        long long now2 = now * now;
        
        val = now;
        return pal(now2);
    }
    void findAll(int in) {
        for(char a='0'; a<='9'; a++) {
            for(char b='0'; b<='9'; b++) {
                for(char c='0'; c<='9'; c++) {
                    for(char d='0'; d<='9'; d++) {
                        
                        string st = "";
                        st += a;
                        st += b;
                        st += c;
                        st += d;
                        
                        string tmp = st;
                        reverse(tmp.begin(), tmp.end());
                        while(tmp.size() > 0 && tmp.back() == '0') tmp.pop_back();
                            
                        string nowSt = st + tmp;
                        int now;
                        if(check(nowSt, now)) {
                            all.push_back(now);
                        }
                        
                        for(char e='0'; e<='9';e++) {
                            string tst = st + e;
                            
                            nowSt = tst + tmp;
                            // cout << tst << " * " << tmp << endl;
                            if(check(nowSt, now)) {
                                // cout << nowSt << " " << now << endl;
                                all.push_back(now);
                            }
                        }
                    }
                }
            }
        }
    }
    int superpalindromesInRange(string L, string R) {
        if(all.size() ==0) {
            findAll(0);
            sort(all.begin(), all.end());
        }
        // for(int i=0;i<20; i++) {
        //     cout << all[i] << endl;
        // }
        long long ll = sTn(L);
        long long rr = sTn(R);
        
        ll = sqrt(ll);
        rr = sqrt(rr);
        
        int lpos = lower_bound(all.begin(), all.end(), (long long)ll) - all.begin();
        int rpos = upper_bound(all.begin(), all.end(), (long long)rr) - all.begin();
        
        // cout << lpos << " " << rpos << " " << ll << " " << rr << endl;
        return rpos - lpos;
    }
};