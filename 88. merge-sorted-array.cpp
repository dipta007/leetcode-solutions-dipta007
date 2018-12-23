class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0, extra = 0;
        
        int del = 0;
        int mm = nums1.size()-m;
        for(int i=nums1.size()-1; del < mm && i>=0; i--)
        {
            if(nums1[i] == 0) 
            {
                nums1.erase(nums1.begin() + i);
                del++;
            }
        }
        
        for(int i=0; i<nums1.size(); i++) cout << nums1[i] << endl;
        
        
        vector <int> v(n+m);
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        nums1 = v;
    }
};