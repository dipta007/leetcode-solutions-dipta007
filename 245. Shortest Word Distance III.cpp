class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map <string, int> mp;
        int dis = INT_MAX;
        mp[word1] = -100000;
        mp[word2] = -100000;
        for(int i=0; i<words.size(); i++) {
            if(words[i] == word1) {
                dis = min(dis, i - mp[word2]);
            }
            else if(words[i] == word2) {
                dis = min(dis, i - mp[word1]);
            }
            mp[words[i]] = i;
        }
        return dis;
    }
};