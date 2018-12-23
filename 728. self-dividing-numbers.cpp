class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector < int > v;
        for(int i=left; i<=right; i++)
        {
            int tmp = i;
            int flg = 1;
            while(tmp)
            {
                int kk = tmp%10;
                if(kk==0 || i % kk != 0)
                {
                    flg = 0;
                    break;
                }
                tmp /= 10;
            }
            
            if(flg)
            {
                v.push_back(i);
            }
        }
        
        return v;
    }
};