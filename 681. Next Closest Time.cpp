class Solution {
    int get(int h, int m, int gh, int gm) {
        int now = h * 60 + m;
        int gnow = gh * 60 + gm;
        
        if(h > 23 || m > 59 || now > 1440) return 140000;
        
        int res = 0;
        if(now <= gnow) res += 1440 - gnow + now;
        else res += now - gnow;
        
        return res;
    }
public:
    string nextClosestTime(string time) {
        int gh = (time[0] - '0') * 10 + (time[1] - '0');
        int gm = (time[3] - '0') * 10 + (time[4] - '0');
        
        set <int> s;
        s.insert(time[0] - '0');
        s.insert(time[1] - '0');
        s.insert(time[3] - '0');
        s.insert(time[4] - '0');
        
        string res;
        int mn = 14000;
        for(auto i: s) {
            for(auto j: s) {
                for(auto k: s) {
                    for(auto l: s) {
                        int h = i*10 + j;
                        int m = k*10 + l;
                        
                        int now = get(h, m, gh, gm);
                        if(now < mn) {
                            mn = now;
                            string tmp = "";
                            tmp += (char)(i+'0');
                            tmp += (char)(j+'0');
                            tmp += ":";
                            tmp += (char)(k+'0');
                            tmp += (char)(l+'0');
                            res = tmp;
                        }
                    }
                }
            }
        }
        return res;
    }
};