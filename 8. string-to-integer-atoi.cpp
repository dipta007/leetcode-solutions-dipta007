class Solution {
public:
    int myAtoi(string str) {
        long long ret = 0;
        int len = str.size();
        int cnt = 0;
        
        int i = 0;
        while(str[i]==' ') i++;
        int st = i;
        for(; i<len; i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
                ret = (ret*10LL) + (str[i] - '0');
            else if(str[i]=='+' || str[i]=='-') cnt++;
            else break;
            
            if(str[st]=='-' && -ret <= -2147483648) 
            {
                ret = 2147483648;
                break;
            }
            if(ret >= INT_MAX) 
            {
                ret = INT_MAX;
                break;
            }
        }
        if(str[st]=='-') ret *= -1;
        if(cnt > 1) ret = 0;
        
        
        return ret;
    }
};