class Solution {
public:
    int dp[100004];
    int call(int in, vector<int> &nums) {
        if(in == nums.size()-1) return 0;
        if(in >= nums.size()) return 0;
        int &ret = dp[in];
        if(ret != -1) return ret;
        
        ret = 1000000;
        for(int i=1; i<=nums[in]; i++) {
            ret = min(ret, 1 + call(in + i, nums));
        }
        return ret;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return call(0, nums);
    }
};