class Solution {
public:
    int mark[404];
    int vis[404];
    int bfs(int src,vector<vector<int>>& board) {
        queue <int> q;
        int dist[404];
        dist[src] = 0;
        vis[src] = 1;
        q.push(src);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == board.size() * board[0].size()) return dist[u];
            for(int i=1; i<=6; i++) {
                int v = u+i;
                if(v > board.size() * board[0].size()) continue;
                cout << u << " " << v << endl;
                if(mark[v] != -1) v = mark[v];
                if(vis[v] == 0) {
                    dist[v] = dist[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int in = 1;
        for(int i=board.size()-1, k=1; i>=0; i--, k ^= 1) {
            if(k == 1) {
                for(int j=0; j<board[i].size(); j++) {
                    mark[in++] = board[i][j];
                }
            }
            else {
                for(int j=board[i].size()-1; j>=0; j--) {
                    mark[in++] = board[i][j];
                }
            }
        }
        
        memset(vis, 0, sizeof vis);
        int ret = bfs(1, board);
        return ret;
    }
};