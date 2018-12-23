vector < vector <int> > tmp;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        vector < int > res;
        
        tmp.assign(200004, vector <int> ());
        
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                nums[i][j] += 1e5;
                tmp [ nums[i][j] ].push_back(i+1);
            }
        }
        
        unordered_map <int, int> mp;
        int cnt = 0;
        
        int mx = 2e5 + 4;
        int sin, ein;
        int low = 0;
        for(int high = 0; high <= 2e5; high++)
        {
            for(int i=0; i<tmp[high].size(); i++)
            {
                if(mp[ tmp[high][i] ]==0) cnt++;
                mp[ tmp[high][i] ]++;
            }
            // if(tmp[high] != 0 && mp[ tmp[high] ] == 0)
            // {
            //     cnt++;
            // }
            // mp[ tmp[high] ] ++;
            
            while( cnt == k )
            {
                if(high - low + 1 < mx)
                {
                    //cout << low << " " << high << endl;
                    mx = high - low + 1;
                    sin = low - 1e5;
                    ein = high - 1e5;
                }
                for(int i=0; i<tmp[low].size(); i++)
                {
                    mp[ tmp[low][i] ]--;
                    if(mp[ tmp[low][i] ] == 0)
                    {
                        cnt--;
                    }
                }
                low++;
            } 
        }
        
        res.push_back(sin);
        res.push_back(ein);
        
        return res;
    }
};