class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int cnt = 1;
        string tmp = A;
        while(A.size() < B.size()) {
            cnt += 1;
            A += tmp;
        }
        
        
        if(A.find(B) != string::npos) {
            // cout << A << " " << A.find(B) << endl;
            return cnt;
        }
        else if((A+tmp).find(B) != string::npos) {
            return cnt+1;
        }
        else if((tmp+A).find(B) != string::npos) {
            return cnt+1;
        }
        return -1;
    }
};