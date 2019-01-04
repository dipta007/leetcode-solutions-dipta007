class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string tmp = "";
        for(int i=(int)S.size()-1, k=0; i>=0;) {
            if(k && k%K == 0) {
                tmp += "-";
                k = 0;
                continue;
            }
            
            if(S[i] == '-') {
                i--;
            }
            else {
                tmp += toupper(S[i]);
                i--, k++;
            }
        }
        
        if(tmp.back() == '-') tmp.pop_back();
        
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};