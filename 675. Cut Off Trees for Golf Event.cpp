int dxx[] = {-1, 1, 0, 0};
int dyy[] = {0, 0, -1, 1};
class Solution {
public:
    int bfs(int sx, int sy, int dx, int dy, vector<vector<int>>& forest) {
        int dist[54][54];
        for(int i=0; i<=50; i++) for(int j=0; j<=50; j++) dist[i][j] = 10000;
        dist[sx][sy] = 0;
        
        queue <int> q;
        q.push(sx);
        q.push(sy);
        
        while(!q.empty()) {
            int ux = q.front(); q.pop();
            int uy = q.front(); q.pop();
            if(ux == dx && uy == dy) return dist[ux][uy];
            for(int i=0; i<4; i++) {
                int vx = ux + dxx[i];
                int vy = uy + dyy[i];
                if(vx >= 0 && vy >= 0 && vx < forest.size() && vy < forest[0].size() && forest[vx][vy] >= 1) {
                    if(dist[vx][vy] > dist[ux][uy] + 1) {
                        dist[vx][vy] = dist[ux][uy] + 1;
                        q.push(vx);
                        q.push(vy);
                    }   
                }
            }
        }
        
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        unordered_map <int, pair<int, int> > mp;
        vector < int > v;
        
        v.push_back(1);
        mp[1] = make_pair(0,0);
        for(int i=0; i<forest.size(); i++) {
            for(int j=0; j<forest[i].size(); j++) {
                if(forest[i][j] > 1) {
                    v.push_back(forest[i][j]);
                    mp[forest[i][j]] = make_pair(i, j);
                }
            }
        }
        
        sort(v.begin(), v.end());
        
        int res = 0;
        for(int i=1; i<v.size(); i++) {
            int s = v[i-1];
            int d = v[i];
            int now = bfs(mp[s].first, mp[s].second, mp[d].first, mp[d].second, forest);
            
            // cout << i << " " << mp[s].first << " " << mp[s].second << " " << mp[d].first << " " << mp[d].second << endl;
            if(now == -1) return -1;
            
            res += now;
        }
        
        return res;
    }
};