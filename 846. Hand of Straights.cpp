class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size() % W != 0) return false;
        if(W == 1) return true;
        
        map <int, int> mp;
        for(int i=0; i<hand.size(); i++) {
            mp[hand[i]] ++;
        }
        
        set <int> s;
        for(auto v: hand) s.insert(v);
        
        while(s.size()) {
            int mx = mp[*s.begin()];
            int val = *s.begin();
            int cnt = 0;
            for(auto ss: s) {
                if(mp[ss] < mx) return 0;
                mp[ss] -= mx;
                if(mp[ss] == 0) s.erase(ss);
                cnt++;
                if(cnt == W) {
                    if(ss != val+W-1) return 0;
                    break;
                }
            }
            if(cnt < W) return 0;
        }
        return true;
    }
};