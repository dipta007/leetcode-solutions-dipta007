class Solution {
public:
    vector <int> ww;
    int max;
    Solution(vector<int> w) {
        srand(time(NULL));
        ww.push_back(w[0]);
        max = w[0];
        
        for(int i=1; i<w.size(); i++) {
            max += w[i];
            ww.push_back(max);
        }
    }
    
    int pickIndex() {
        int kk = rand() % max + 1;
        int low = lower_bound(ww.begin(), ww.end(), kk) - ww.begin();
        // cout << kk << " " << low << endl;
        // if(binary_search(ww.begin(), ww.end(), kk)) low--;
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */