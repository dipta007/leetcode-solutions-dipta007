class Solution {
    struct node {
        int endPoint;
        node *val[30];
        node() {
            endPoint = false;
            for(int i=0; i<30; i++) val[i] = NULL;
        }
    } *root;
    
    void insert(node *curr, string &st) {
        for(int i=0; i<st.size(); i++) {
            int id = st[i] - 'a';
            if(curr->val[id] == NULL) curr->val[id] = new node();
            curr = curr->val[id];
        }
        curr->endPoint = true;
    }
    
    vector < string > combine(string &st, vector<string> &v) {
        vector < string > ret;
        for(int i=0; i<v.size(); i++) {
            if(v[i].size()) ret.push_back(st + " " + v[i]);
            else ret.push_back(st);
        }
        return ret;
    }
    
    unordered_map <int, vector<string> > mp;
    vector<string> dfs(node *curr, int in, string &st) {
        if(mp.count(in)) return mp[in];
        
        // cout << in << endl;
        
        vector <string> ret;
        string now = "";
        for(int i=in; i<st.size(); i++) {
            int id = st[i] - 'a';
            if(curr->val[id] != NULL) {
                now += st[i];
                curr = curr->val[id];
                
                if(curr->endPoint) {
                    vector <string> fut = dfs(root, i+1, st); 
                    vector <string> prev = combine(now,  fut);
                    ret.insert(ret.end(), prev.begin(), prev.end());
                }
            }
            else break;
        }
        
        mp[in] = ret;
        return ret;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new node();
        for(int i=0; i<wordDict.size(); i++) {
            insert(root, wordDict[i]);
        }
        vector<string> df;
        df.push_back("");
        mp[s.size()] = df;
        return dfs(root, 0, s);
    }
};