class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int rgt[seats.size() + 4];
        int right = seats.size()+1000000;
        for(int i=seats.size()-1; i>=0; i--) {
            if(seats[i] == 1) {
                rgt[i] = 0;
                right = i;
            }
            else {
                rgt[i] = right - i;
            }
        }
        
        int left = -100000;
        int res = -100;
        for(int i=0; i<seats.size(); i++) {
            if(seats[i] == 1) {
                res = max(0, res);
                left = i;
                continue;
            }
            int now = min(i-left, rgt[i]);
            res = max(res, now);
        }
        
        return res;
    }
};