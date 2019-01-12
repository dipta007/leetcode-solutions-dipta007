class RLEIterator {
public:
    stack <int> val, cnt;
    RLEIterator(vector<int> A) {
        for(int i=A.size()-1; i>=0; i-=2) {
            val.push(A[i]);
            cnt.push(A[i-1]);
        }
    }
    
    int next(int n) {
        int res = -1;
        while(n && val.size()) {
            int need = n;
            int ase = cnt.top(); cnt.pop();
            res = val.top(); val.pop();
            
            int kk = min(need, ase);
            ase -= kk;
            n -= kk;
            
            if(ase) {
                cnt.push(ase);
                val.push(res);
            }
        }
        // cout << n << " " << st.size() << endl;
        if(n) res = -1;
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */