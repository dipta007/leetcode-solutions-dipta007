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
    return a.start < b.start;
}
class Solution {
    
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        
        priority_queue <int, vector<int>, greater<int> > pq;
        pq.push(intervals[0].end);
        
        int res = 1;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i].start >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i].end);
            
            res = max(res, (int)pq.size());
        }
        return res;
    }
};