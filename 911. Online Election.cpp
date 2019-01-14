class TopVotedCandidate {
public:
    vector <int> rtimes, res;
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        rtimes = times;
        int top = 0, ind;
        map <int, int> mp;
        for(int i=0; i<times.size(); i++) {
            mp[persons[i]]++;
            if(mp[persons[i]] >= top) {
                top = mp[persons[i]];
                ind = persons[i];
            }
            res.push_back(ind);
        }
    }
    
    int q(int t) {
        int pos = lower_bound(rtimes.begin(), rtimes.end(), t) - rtimes.begin();
        if(binary_search(rtimes.begin(), rtimes.end(), t) == false) pos--;
        
        return res[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */