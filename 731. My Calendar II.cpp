class MyCalendarTwo {
    map<int, int> mp;
public:
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int cnt = 0;
        for(auto v: mp) {
            cnt += v.second;
            if(cnt >= 3) {
                mp[start]--;
                mp[end]++;
                
                if(mp[start] == 0) mp.erase(start);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */