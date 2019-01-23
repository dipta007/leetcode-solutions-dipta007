class Solution {
public:
    int partition(int l, int r, int ind, vector<int> &nums) {
        int pivot = nums[ind];
        swap(nums[r], nums[ind]);
        int now = l;
        for(int i=l; i<=r; i++) {
            if(nums[i] < pivot) {
                swap(nums[i], nums[now]);
                now++;
            }
        }
        swap(nums[now], nums[r]);
        return now;
    }
    int quick_select(int l, int r, vector<int> &nums, int k) {
        int rr = rand() % (r-l+1);
        rr = l + rr;
        
        rr = partition(l, r, rr, nums);
        
        if(rr == k) {
            return nums[rr];
        }
        else {
            if(rr < k) {
                return quick_select(rr+1, r, nums, k);
            }
            else {
                return quick_select(l, rr-1, nums, k);
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(0, nums.size()-1, nums, nums.size()-k);
        
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};