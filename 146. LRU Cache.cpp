class LRUCache {
public:
    int cap;
    unordered_map <int, int> val, cnt;
    int sz;
    deque <int> dq;
    LRUCache(int capacity) {
        cap = capacity;
        val.clear(), cnt.clear();
        sz = 0;
        dq.clear();
    }
    
    int get(int key) {
        if(cnt[key] == 0) return -1;
        dq.push_back(key);
        cnt[key]++;
        return val[key];
    }
    
    void put(int key, int value) {
        if(cnt[key] == 0) sz++;
        dq.push_back(key);
        cnt[key]++;
        val[key] = value;
        
        // cout << key << " " << value << " " << sz << endl;
        
        while(sz > cap) {
            int top = dq.front();
            cnt[top] --;
            if(cnt[top] == 0) sz--;
            dq.pop_front();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */