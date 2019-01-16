class RandomizedSet {
public:
    unordered_map <int, int> mp;
    vector <int> v;
    /** Initialize your data structure here. */
    RandomizedSet() {
        mp.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp[val] != 0) return false;
        mp[val] = v.size()+1;
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp[val] == 0) return false;
        int pos = mp[val]-1;
        swap(v[pos], v[v.size()-1]);
        mp[v[pos]] = pos+1;
        v.pop_back();
        mp[val] = 0;
        cout << v.size() << " " << endl;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int ind = rand()%v.size();
        return v[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */