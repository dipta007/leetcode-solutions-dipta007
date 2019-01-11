class Solution {
public:
    struct data {
        int ind;
        string src, dest;
        bool const operator<(const data &a) const {
            return ind < a.ind;
        }
    };
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector <data> vd;
        for(int i=0; i<indexes.size(); i++) {
            data d;
            d.ind = indexes[i];
            d.src = sources[i];
            d.dest = targets[i];
            vd.push_back(d);
        }
        sort(vd.begin(), vd.end());
        int cnt = 0;
        for(int i=0; i<vd.size(); i++) {
            int ind = vd[i].ind;
            string src = vd[i].src;
            string dest = vd[i].dest;
            
            if(S.substr(ind + cnt, src.size()) == src) {
                S.replace(ind + cnt, src.size(), dest);  
                cnt += (dest.size() - src.size());
            }
        }
        return S;
    }
};