class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int flg = 0;
        if(x < 0) flg = 1;
        while(x)
        {
            int kk = x%10;
            res = res*10 + kk;
            x/=10;
        }
        
        // if(flg) res *= -1;
        
        if(res < INT_MIN)
        {
            res = 0;
        }
        
        if(res > INT_MAX)
        {
            res = 0;
        }
        
        return res;
    }
};