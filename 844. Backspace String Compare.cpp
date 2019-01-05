class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string tmp = "";
        for(int i=0; i<S.size(); i++) {
            if(S[i] == '#') {
                if(tmp.size() > 0) tmp.pop_back();
                continue;
            }
            tmp += S[i];
        }
        S = tmp;
        
        tmp = "";
        for(int i=0; i<T.size(); i++) {
            if(T[i] == '#') {
                if(tmp.size() > 0) tmp.pop_back();
                continue;
            }
            tmp += T[i];
        }
        T = tmp;
        
        return S==T;
    }
};