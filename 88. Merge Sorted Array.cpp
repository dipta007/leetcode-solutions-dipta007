class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1 = m-1, l2 = n-1, r = n+m-1;
        
        while(1) {
            if(l1 >= 0 && l2 >= 0) {
                if(nums1[l1] >= nums2[l2]) {
                    nums1[r] = nums1[l1];
                    l1--;
                }
                else {
                    nums1[r] = nums2[l2];
                    l2--;
                }
            }
            else if(l1 >= 0) {
                nums1[r] = nums1[l1];
                l1--;
            }
            else if(l2 >= 0){
                nums1[r] = nums2[l2];
                l2--;
            }
            else break;
            r--;
        }
    }
};