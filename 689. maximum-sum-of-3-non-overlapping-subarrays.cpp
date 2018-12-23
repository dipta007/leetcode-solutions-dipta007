class Solution {
    int cum[20004];
    int dp[20004][4];
    int path[20004][4];
    
    int call(int in, int kk, int n, int k) {
        if(kk == 0) return 0;
        if(in > n-k) return -100000000;
        
        int &ret = dp[in][kk];
        if(ret != -1) return ret;
        
        ret = -2000000000;
        
        int now;
        if(in == 0) now = cum[in+k-1];
        else now = cum[in+k-1] - cum[in-1];
        
        int tmp = now + call(in+k, kk-1, n, k);
        
        if(tmp > ret) {
            ret = tmp;
            path[in][kk] = 1;
        }
        
        tmp = call(in+1, kk, n, k);
        if(tmp > ret) {
            ret = tmp;
            path[in][kk] = 2;
        }
        return ret;
    }
    vector <int> res;
    void call1(int in, int kk, int n, int k) {
        if(kk == 0) return;
        if(in > n-k) return;
        
        int now = path[in][kk];
        
        if(now == 2) {
            call1(in+1, kk, n, k);
        }
        else {
            res.push_back(in);
            call1(in+k, kk-1, n, k);
        }
        return;
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++) {
            if(i) cum[i] = cum[i-1] + nums[i];
            else cum[i] = nums[i];
        }
        memset(dp, -1, sizeof dp);
        
        int ans = call(0, 3, nums.size(), k);
        // cout << ans << endl;
        res.clear();
        call1(0, 3, nums.size(), k);
        return res;
    }
};