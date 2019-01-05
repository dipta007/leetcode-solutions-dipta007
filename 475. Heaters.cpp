class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int res = 0;
        for(int i=0; i<houses.size(); i++) {
            int l = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int r = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            
            if(heaters[l] != houses[i] && l != 0) l--;
            if(r >= heaters.size()) r--;
            int now = min(abs(houses[i] - heaters[l]), abs(heaters[r] - houses[i]));
            cout << now << endl;
            res = max(res, now);
        }
        return res;
    }
};