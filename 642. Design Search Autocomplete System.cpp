class AutocompleteSystem {
    struct node {
        int times;
        bool endPoint;
        node *id[30];
        node() {
            for(int i=0; i<30; i++) id[i] = NULL;
            times = 0;
            endPoint = false;
        }
    } *root;
    
    void insert(string &stt, node *curr, int times) {
        for(int i=0; i<stt.size(); i++) {
            int kk = stt[i] - 'a' + 1;
            if(stt[i] == ' ') kk = 0;
            
            if(curr->id[kk] == NULL)
                curr->id[kk] = new node();
            
            curr = curr->id[kk];
        }
        curr->endPoint = true;
        curr->times += times;
    }
    
    vector <pair<int, string> > res;
    void dfs(node *curr, string st) {
        for(int i=0; i<30; i++) {
            if(curr->id[i]) {
                char c = (i-1) + 'a';
                if(i == 0) c = ' ';
                dfs(curr->id[i], st + c);
            }
        }
        if(curr->endPoint) {
            res.push_back(make_pair(-curr->times, st));
        }
    }
    
    void get(string &st, node *curr) {
        res.clear();
        for(int i=0; i<st.size(); i++) {
            int kk = st[i] - 'a' + 1;
            if(st[i] == ' ') kk = 0;
            
            if(curr->id[kk] == NULL) return;
            
            curr = curr->id[kk];
        }
        dfs(curr, st);
        sort(res.begin(), res.end());
    }
public:
    string st;
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new node();
        for(int i=0; i<sentences.size(); i++) {
            insert(sentences[i], root, times[i]);
        }
        st = "";
    }
    
    vector<string> input(char c) {
        vector <string> ret;
        ret.clear();
        if(c == '#') {
            insert(st, root, 1);
            st = "";
            return ret;
        }
        st += c;
        get(st, root);
        
        for(int i=0; i<res.size(); i++) {
            ret.push_back(res[i].second);
            if(i == 2) break;
        }
        
        return ret;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */