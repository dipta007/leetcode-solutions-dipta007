class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int mn = nums[0];
        for(int i=1; i<nums.size(); i++) {
            mn = min(mn, nums[i]);
        }
        
        int ret = 0;
        for(int i=0; i<nums.size(); i++) {
            ret += (nums[i] - mn);
        }
        
        return ret;
    }
};