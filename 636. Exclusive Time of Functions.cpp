class Solution {
    void get(string &st, int &id, int &event, int &tt) {
        id = 0;
        int i = 0;
        for(; st[i]!=':'; i++) {
            int kk = st[i] - '0';
            id = id * 10 + kk;
        }
        
        event = 0;
        i++;
        if(st[i] == 'e') event = 1;
        while(st[i] != ':') i++;
        
        i++;
        tt = 0;
        
        while(i < st.size()) {
            int kk = st[i] - '0';
            tt = tt*10 + kk;
            i++;
        }
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack <int> st;
        vector <int> v(n, 0);
        
        int id, event, tt;
        get(logs[0], id, event, tt);
        int prev = id, prevTime = tt;
        st.push(id);
        for(int i=1; i<logs.size(); i++) {
            get(logs[i], id, event, tt);
            
            // cout << id << " " << tt << " " << prev << " " << prevTime << endl;
            if(event == 0) {
                if(prev != -1)
                    v[prev] += (tt - prevTime);
                prev = id;
                prevTime = tt;
                st.push(id);
            }
            else {
                st.pop();
                if(prev != -1)
                    v[prev] += (tt - prevTime + 1);
                if(st.size()) {
                    prev = st.top();
                }
                else prev = -1;
                prevTime = tt+1;
            }
        }
        
        return v;
    }
};