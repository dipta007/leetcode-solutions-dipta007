class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int res = nums[0];
        while(low <= high) {
            int mid = (low + high) >> 1;
            
            if(nums[mid] >= nums[0]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                res = nums[mid];
            }
        }
        
        return res;
    }
};