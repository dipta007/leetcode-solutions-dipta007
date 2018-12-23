class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x!=0 && x%10==0) return false;
        
        int res = 0;
        while(res < x)
        {
            res = res*10 + x%10;
            x/=10;
        }
        
        if(res==x || res/10==x) return true;
        return false;
    }
};