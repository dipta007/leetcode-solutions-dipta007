class MedianFinder {
public:
    priority_queue <int> maxy;
    priority_queue <int, vector<int>, greater<int> > mini;
    double median;
    /** initialize your data structure here. */
    MedianFinder() {
        while(!maxy.empty()) maxy.pop();
        while(!mini.empty()) mini.pop();
        median = 0;
    }
    
    void addNum(int num) {
        mini.push(num);
        
        maxy.push(mini.top());
        
        mini.pop();
        
        if(mini.size() < maxy.size()) {
            mini.push(maxy.top());
            maxy.pop();
        }
    }
    
    double findMedian() {
        if((mini.size() + maxy.size()) & 1) return mini.top();
        else return (mini.top() + maxy.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */