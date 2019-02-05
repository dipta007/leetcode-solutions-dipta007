class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map < string, int > mp;
        for(int i=0; i<cpdomains.size(); i++) {
            string st = cpdomains[i];
            
            int now = 0;
            int l = 0;
            while(st[l] != ' ') {
                int kk = st[l] - '0';
                now = now * 10 + kk;
                l++;
            }
            
            string tmp = "";
            for(int j=st.size()-1; j>l; j--) {
                if(st[j] == '.') {
                    mp[tmp] +=now;
                }
                tmp = st[j] + tmp; 
            }
            mp[tmp]+=now;
        }
        
        vector < string > vs;
        for(auto &v: mp) {
            
            cout << v.first << " " << v.second << endl;
            vs.push_back(to_string(v.second) + " " + v.first);
        }
        return vs;
    }
};