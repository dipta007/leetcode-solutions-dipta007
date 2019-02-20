class Solution {
    vector <string> res;
    void call(int n, int tot, int rem, string lft, string rgt) {
        if(n == 0) {
            if(rem) {
                res.push_back(lft+'1'+rgt);
                res.push_back(lft+'8'+rgt);
                res.push_back(lft+'0'+rgt);
            }
            else res.push_back(lft + rgt);
            return;
        }
        if(n < tot) {
            call(n-1, tot, rem, lft + "0", "0" + rgt);
        }
        call(n-1, tot, rem, lft + "1", "1" + rgt);
        call(n-1, tot, rem, lft + "6", "9" + rgt);
        call(n-1, tot, rem, lft + "9", "6" + rgt);
        call(n-1, tot, rem, lft + "8", "8" + rgt);
        
    }
public:
    vector<string> findStrobogrammatic(int n) {
        res.clear();
        call(n/2, n/2, n%2, "", "");
        return res;
    }
};