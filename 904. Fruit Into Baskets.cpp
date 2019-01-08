class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int low = 0;
        unordered_map <int, int> mp;
        int cnt = 0;
        int res = 0;
        for(int high=0; high<tree.size(); high++) {
            mp[tree[high]]++;
            if(mp[tree[high]] == 1) cnt++;
            while(cnt > 2) {
                mp[tree[low]]--;
                if(mp[tree[low]] == 0) cnt--;
                low++;
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};