class Solution {
    vector < vector <int> > adj;
    int in[100];
    set <int> s;
public:
    void dfs(int l, int r, int ind, vector <string> &words) {
        if(r - l + 1 == 1) return;
        int lft = l;
        while(words[lft].size() <= ind) lft++;
        int flg = 0;
        for(int i=l+1; i<=r; i++) {
            if(ind < words[i].size()) flg = 1;
            if(ind < words[i].size() && ind < words[i-1].size() && words[i][ind] != words[i-1][ind]) {
                dfs(lft, i-1, ind+1, words);
                
                int prev = words[i-1][ind] - 'a';
                int now = words[i][ind] - 'a';
                adj[prev].push_back(now);
                cout << l << " " << r << " " << ind << " "<< prev << " " << now << endl;
                in[now]++;
                
                // s.insert(prev);
                s.insert(now);
                
                lft = i;
            }
        }
        
        if(lft != l || (flg)) dfs(lft, r, ind+1, words);
    }
    string alienOrder(vector<string>& words) {
        adj.assign(40, vector <int> ());
        memset(in, 0, sizeof in);
        s.clear();
        
        for(auto &u: words) {
            for(auto v: u) {
                s.insert((int)(v-'a'));
            }
        }
        
        dfs(0, words.size()-1, 0, words);
        queue <int> q;
        
        for(auto v: s) if(in[v] == 0) q.push(v);
        
        string res = "";
        while(!q.empty()) {
            int u = q.front(); q.pop();
            cout << (char)(u+'a') << " " << in['k'-'a']<< endl;
            res += (char)(u + 'a');
            for(auto v: adj[u]) {
                in[v]--;
                if(in[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(res.size() != s.size()) res = "";
        return res;
    }
};