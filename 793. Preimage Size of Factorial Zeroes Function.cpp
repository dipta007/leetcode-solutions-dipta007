class Solution {
    long long check(long long x) {
        long long res = 0;
        while(x) {
            res += (x/5);
            x /= 5;
        }
        return res;
    }
public:
    int preimageSizeFZF(int K) {
        long long low = 0, high = 20000000000000;
        
        long long res = 0;
        while(low <= high) {
            long long mid = (low + high) / 2;
            // cout << mid << " " << check(mid) << endl;
            
            if(check(mid) <= K) {
                low = mid + 1;
                res = mid;
            }
            else high = mid - 1;
        }
        
        if(check(res) == K) return 5;
        return 0;
    }
};