class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector <int> odd, even;
        for(int i=0; i<A.size(); i++) {
            if(A[i] % 2 == 0) {
                even.push_back(A[i]);
            }
            else {
                odd.push_back(A[i]);
            }
        }
        vector <int> res;
        res.reserve(odd.size() + even.size());
        res.insert(res.end(), even.begin(), even.end());
        res.insert(res.end(), odd.begin(), odd.end());
        return res;
    }
};