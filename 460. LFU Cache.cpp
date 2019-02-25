class LFUCache {
    priority_queue < pair<int, pair<int,int> > > pq;
    unordered_map <int, int> cnt, val;
    int tt, cap, sz;
public:
    LFUCache(int capacity) {
        // pq.clear();
        val.clear();
        tt = 0;
        cap = capacity;
        sz = 0;
    }
    
    int get(int key) {
        if(cap == 0) return -1;
        tt++;
        if(cnt[key] == 0) return -1;
        
        cnt[key]++;
        pq.push(make_pair(-cnt[key], make_pair(-tt, key)));
        return val[key];
    }
    
    void invalidate() {
        while(sz > cap && pq.size()) {
            int kk = pq.top().second.second;
            cout << kk << " " << cnt[kk] << " " << pq.top().first << " " << pq.top().second.first << " " << sz << endl;
            if(cnt[kk] == -pq.top().first) {
                cout << kk << endl;
                sz--;
                cnt[kk] = 0;
            }  
            pq.pop();
        }
    }
    
    void put(int key, int value) {
        tt++;
        val[key] = value;
        if(cnt[key] == 0) sz++;
        invalidate();
        cnt[key]++;
        pq.push(make_pair(-cnt[key], make_pair(-tt, key)));
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */