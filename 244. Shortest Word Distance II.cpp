class WordDistance {
public:
    unordered_map <string, set <int> > mp;
    WordDistance(vector<string> words) {
        for(int i=0; i<words.size(); i++) {
            mp[words[i]].insert(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto &s1 = mp[word1];
        auto &s2 = mp[word2];
        
        int dis = INT_MAX;
        for(int v: s1) {
            auto tmp = s2.lower_bound(v);
            if(tmp != s2.end()) {
                dis = min(dis, *tmp - v);
            }
        }
        
        
        for(int v: s2) {
            auto tmp = s1.lower_bound(v);
            if(tmp != s1.end()) {
                dis = min(dis, *tmp - v);
            }
        }
        
        return dis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */