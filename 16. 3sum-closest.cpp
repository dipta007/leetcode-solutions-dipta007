class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int mn = INT_MAX;
        int res;
        for(int i=0; i<sz; i++)
        {
            int low = i+1;
            int high = sz-1;
            
            while(low < high)
            {
                if( abs(target- (nums[i] + nums[low] + nums[high]) ) < mn )
                {
                    mn = abs(target- (nums[i] + nums[low] + nums[high]) );
                    res = (nums[i] + nums[low] + nums[high]);
                }
                else if((nums[i] + nums[low] + nums[high]) <= target)
                {
                    low ++;
                }
                else if((nums[i] + nums[low] + nums[high]) > target)
                {
                    high--;
                }
            }
        }
        
        return res;
    }
};