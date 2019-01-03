#define ll long long
class Solution {
public:
    bool check(int x, int m, int n, int k) {
        int cnt = 0;
        for(int i=1; i<=m; i++) {
            cnt += min(x/i, n);
        }
        return cnt >= k;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 0, high = 30000LL * 30000LL;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(mid, m, n, k)) {
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};