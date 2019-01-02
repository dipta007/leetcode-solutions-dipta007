struct trie {
    trie * arr[27];
    int endpoint;
    trie() {
        for(int i=0; i<26; i++) arr[i] = NULL;
        endpoint = 0;
    }
};

void insert(string &st, trie * curr) {
    int len = st.size();
    for(int i=0; i<len; i++) {
        int id = st[i] - 'a';
        if(curr->arr[id] == NULL) {
            curr->arr[id] = new trie();
        }
        curr = curr->arr[id];
    }
    curr->endpoint = 1;
}

bool find(string &st, int in, int flg, trie * curr) {
    int id = st[in] - 'a';
    if(in >= st.size()) {
        return curr->endpoint && flg == 1;
    }

    int ret = 0;
    if(curr->arr[id] != NULL) {
        ret = ret || find(st, in+1, flg, curr->arr[id]);   
    }

    if(flg == 0) {
        for(int i=0; i<26; i++) {
            if(i != id && curr->arr[i] != NULL) {
                ret = ret || find(st, in+1, 1, curr->arr[i]);
            }
        }
    }

    return ret;
}

trie * root;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new trie();   
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0; i<dict.size(); i++) {
            insert(dict[i], root);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return find(word, 0, 0, root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */