#define pii pair <int, int>
#define piii pair <int, pii>
#include <unordered_map>

class LRUCache {
public:
    unordered_map <int, int> keyTime, keyValue, timeKey;
    set <int> s;
    int cap;
    int timee;
    LRUCache(int capacity) {
        cap = capacity;
        timee = 0;
        keyTime.clear();
        keyValue.clear();
        timeKey.clear();
        s.clear();
    }
    
    int get(int key) {
        if(keyTime[key]==0) return -1;
        
        timee++;
        int timeToUp = keyTime[key];
        s.erase(timeToUp);
        timeKey[timeToUp] = 0;
        timeKey[timee] = key;
        keyTime[key] = timee;
        s.insert(timee);
        return keyValue[key];
    }
    
    void put(int key, int value) {
        if(keyTime[key] == 0)
        {
            //cout << key << " " << s.size() << endl;
            if(s.size()==cap)
            {
                //cout << key << value << endl;
                int timeToRm = *s.begin();
                int keyToRm = timeKey[ timeToRm ];
                //cout << timeToRm << keyToRm << endl;
                keyTime[ keyToRm ] = 0;
                s.erase(timeToRm);
            }
            timee++;
            keyTime[key] = timee;
            timeKey[timee] = key;
            keyValue[key] = value;
            s.insert(timee);
        }
        else
        {
            timee++;
            int timeToUp = keyTime[key];
            s.erase(timeToUp);
            timeKey[timeToUp] = 0;
            
            timeKey[timee] = key;
            keyTime[key] = timee;
            keyValue[key] = value;
            s.insert(timee);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */