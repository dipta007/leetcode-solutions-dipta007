class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int init = 0;
        for(int i=0; i<k; i++) {
            init += abs(arr[i] - x);
        }
        
        int res = init;
        int strt = 0, endd = k-1;
        for(int i=k; i<arr.size(); i++) {
            init += abs(arr[i] - x);
            init -= abs(arr[i-k] - x);
            
            if(init < res) {
                res = init;
                strt = i-k+1;
                endd = i;
            }
        }
        
        vector <int> ret;
        for(int i=strt; i<=endd; i++) {
            ret.push_back(arr[i]);
        }
        return ret;
     }
};