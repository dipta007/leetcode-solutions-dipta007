/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval &a, const Interval &b)
{
    if (a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}
class Solution
{
  public:
    int eraseOverlapIntervals(vector<Interval> &intervals)
    {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 0;
        int endd = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start >= endd)
            {
                endd = intervals[i].end;
            }
            else
                cnt++;

            endd = min(endd, intervals[i].end);
        }

        return cnt;
    }
};