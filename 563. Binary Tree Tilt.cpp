class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int v1, v2;
        v1 = v2 = -10000000;
        int ret = 10000000;
        for(int i=0; i<words.size(); i++) {
            if(words[i] == word1) {
                ret = min(ret, i - v2);
                v1 = i;
            }
            else if(words[i] == word2) {
                ret = min(ret, i - v1);
                v2 = i;
            }
        }
        return ret;
    }
};