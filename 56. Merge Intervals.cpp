/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval &a, const Interval &b) {
    if(a.start < b.start) return true;
    if(a.start == b.start) return a.end > b.end;
    return false;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector <Interval> res;
        for(int i=0; i<intervals.size();) {
            int strt = intervals[i].start;
            int endd = intervals[i].end;
            
            while(i < intervals.size() && intervals[i].start <= endd) {
                endd = max(endd, intervals[i].end);
                i++;
            }
            
            res.push_back(Interval(strt, endd));
        }
        
        return res;
    }
};