#define ff first
#define ss second

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        vector <pair<int,int> > vp;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j])
                    vp.push_back(make_pair(i, j));
            }
        }
        
        int cnt = 0;
        for(int i=0; i<vp.size(); i++) {
            for(int j=i+1; j<vp.size(); j++) {
                if(vp[i].ff == vp[j].ff || vp[i].ss == vp[j].ss)
                    continue;
                if(vp[j].ss < vp[i].ss) continue;
                
                if(grid[vp[i].ff][vp[j].ss] && grid[vp[j].ff][vp[i].ss]) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};