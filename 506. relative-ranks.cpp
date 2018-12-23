class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector < pair <int, int > > vp;
        for(int i=0; i<nums.size(); i++) {
            vp.push_back(make_pair(nums[i], i));
        }
        sort(vp.rbegin(), vp.rend());
        vector <string> res(nums.size());
        for(int i=0; i<vp.size(); i++) {
            if(i == 0) res[vp[i].second] = "Gold Medal";
            else if(i == 1) res[vp[i].second] = "Silver Medal";
            else if(i== 2) res[vp[i].second] = "Bronze Medal";
            else res[vp[i].second] = to_string(i+1);
        }
        return res;
    }
};