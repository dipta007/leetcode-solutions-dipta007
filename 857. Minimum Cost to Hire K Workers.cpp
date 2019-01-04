struct data {
    int q, w;
    double wbq;
};

const double EPS = 1e-9;

bool cmp(const data &a, const data &b) {
    if(a.wbq+EPS <= b.wbq) return true;
    return false;
}

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector <data> vd;
        for(int i=0; i<wage.size(); i++) {
            data d;
            d.q = quality[i];
            d.w = wage[i];
            d.wbq = (double)d.w / d.q;
            vd.push_back(d);
        }
        
        sort(vd.begin(), vd.end(), cmp);
        
        priority_queue <int> pq;
        double ans = 1e9;
        double sumq = 0;
        for(int i=0; i<vd.size(); i++) {
            pq.push(vd[i].q);
            sumq += vd[i].q;
            if(pq.size() > K) {
                sumq += -pq.top();
                pq.pop();
            }
            if(pq.size() == K) {
                ans = min(ans, sumq * vd[i].wbq);
            }
        }
        return ans;
    }
};
