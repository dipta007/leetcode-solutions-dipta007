class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map < pair<int, int>, int > mp;
        sort(points.begin(), points.end());
        
        int res = 100000000;
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                if(points[j][0] == points[i][0]) {
                    pair <int, int> p = make_pair(points[i][1], points[j][1]);
                    if(mp.find(p) != mp.end()) {
                        res = min(res, abs(points[i][0] - mp[p]) * abs(points[i][1] - points[j][1]));
                    }
                    
                    mp[make_pair(points[i][1], points[j][1])] = points[i][0];
                }
                else break;
            }
        }
        if(res == 100000000) res = 0;
        return res;
    }
};