class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        vector <int> res;
        for(int i=0; i<nums.size(); i++) {
            int kk = target - nums[i];
            if(mp[kk]) {
                res.push_back(mp[kk]-1);
                res.push_back(i);
                break;
            }
            mp[nums[i]] = i+1;
        }
        return res;
    }
};