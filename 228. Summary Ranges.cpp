class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector <string> res;
        if(nums.size() == 0) return res;
        int prev = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[i-1] + 1) {
                if(prev == i-1) {
                    res.push_back(to_string(nums[prev]));
                }
                else {
                    res.push_back(to_string(nums[prev]) + "->" + to_string(nums[i-1]));
                }
                
                prev = i;
            }
        }
        
        if(prev == nums.size()-1) {
            res.push_back(to_string(nums[prev]));
        }
        else {
            res.push_back(to_string(nums[prev]) + "->" + to_string(nums[nums.size()-1]));
        }
        
        return res;
    }
};