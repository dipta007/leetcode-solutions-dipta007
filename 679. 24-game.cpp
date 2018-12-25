bool call(vector <double> &v) {    
    // cout << v.size() << " " << v[0] << " " << v[1] << endl;
    cout << v.size() << endl;
    if(v.size() == 0) return false;
    if(v.size() == 1) return (abs(v[0] - 24) < 1e-6);

    bool ret = false;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v.size(); j++) {
            if(i == j) continue;
            
            vector < double > tmp;
            for(int k=0; k<v.size(); k++) {
                if(k == i || k == j) continue;
                tmp.push_back(v[k]);
            }
            
            for (int k = 0; k < 4; k++) {
                if (k < 2 && j > i) continue;
                if (k == 0) tmp.push_back(v[i] + v[j]);
                if (k == 1) tmp.push_back(v[i] * v[j]);
                if (k == 2) tmp.push_back(v[i] - v[j]);
                if (k == 3) {
                    if (v[j] != 0) {
                        tmp.push_back(v[i] / v[j]);
                    } else {
                        continue;
                    }
                }
                if (call(tmp)) return true;
                tmp.pop_back();
            }
        }
    }

    return ret;
}
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector <double> now;
        for(int i=0; i<nums.size(); i++) now.push_back(nums[i]);
        return call(now);
    }
};