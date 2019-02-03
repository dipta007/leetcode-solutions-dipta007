class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector < int > v;
        unordered_map <int, bool> mp;
        
        for(int i=0; i<nums1.size(); i++) {
            mp[nums1[i]] = true;
        }
        
        for(int i=0; i<nums2.size(); i++) {
            if(mp[nums2[i]]) {
                v.push_back(nums2[i]);
                mp[nums2[i]] = false;
            }
        }
        return v;
    }
};