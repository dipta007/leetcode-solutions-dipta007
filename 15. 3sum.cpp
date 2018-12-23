#define ff first
#define ss second
#define pii pair < int, int > 

class Solution {
public:
    
    pii find(vector < pii > &vp, int strt, int end, int val)
    {
        int low = strt, high = end;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(vp[mid].ff < val)
            {
                low = mid + 1;
            }
            else if(vp[mid].ff > val)
            {
                high = mid - 1;
            }
            else return vp[mid];
        }
        return pii(-1, -1);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        cout << nums.size() << endl;
        
        vector < vector < int > > res;
        
        vector < pii > vp;
        unordered_map <int, int> count;
        for(int i=0; i<nums.size(); i++)
        {
            count[ nums[i] ]++; 
        }
        
        unordered_map <int, int> :: iterator it;
        for(it=count.begin(); it!=count.end(); it++)
        {
            vp.push_back( pii(it->ff, it->ss) );
        }
        
        sort(vp.begin(), vp.end());
        
        int len = vp.size();
        
        for(int i=0; i<len; i++)
        {
            
            if(vp[i].ss > 1)
            {
                int now = vp[i].ff + vp[i].ff;
                pii p = find(vp, i+1, len-1, -now);
                if(p.ff != -1)
                {   
                    res.push_back({ vp[i].ff, vp[i].ff, -now });
                }    
            }
            
            if(vp[i].ff==0 && vp[i].ss>2)
            {
                res.push_back({0,0,0});
            }
            
            for(int j=i+1; j<len; j++)
            {
                int now = vp[i].ff + vp[j].ff;
                if(-now == vp[j].ff && vp[j].ss > 1)
                {
                    res.push_back({vp[i].ff, vp[j].ff, -now});
                    continue;
                }
                pii p = find(vp, j+1, len-1, -now);
                if(p.ff != -1)
                {
                    res.push_back({vp[i].ff, vp[j].ff, -now});
                }
            }
        }
        
        
        
        return res;
    }
};