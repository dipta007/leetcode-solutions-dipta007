class Solution {
public:
    string minWindow(string s, string t) {
        int freq[100];
        memset(freq, 0, sizeof freq);
        
        for(int i=0; i<t.size(); i++)
        {
            int kk = t[i] - 'A';
            freq[kk] ++;
        }
        
        int tmp[100];
        int uni = 0;
        memset(tmp, 0, sizeof tmp);
        for(int i=0; i<t.size(); i++)
        {
            int kk = t[i] - 'A';
            if(tmp[kk] == 0) uni++;
            tmp[kk] = 1;
        }
        
        memset(tmp, 0, sizeof tmp);
        
        
        int low = 0;
        int cnt = 0;
        int mn = s.size() + 2;
        string res = "";
        int in;
        for(int high = 0; high < s.size(); high++)
        {
            int kk = s[high] - 'A';
            tmp[kk] ++;
            if(tmp[kk] == freq[kk])
            {
                cnt++;
            }
            
            while(cnt >= uni)
            {
                if(high - low + 1 < mn)
                {
                    mn = high - low + 1;
                    in = low;
                }
                
                int nw = s[low] - 'A';
                tmp[nw] -- ;
                if(tmp[nw] < freq[nw])
                {
                    cnt--;
                }
                low++;
            }
        }
        if(mn <= s.size()) res = s.substr(in, mn);
        return res;
    }
};