#define pis pair<int, string>

class Solution {
public:
    string findContestMatch(int n) {
        priority_queue < pis, vector<pis>, greater<pis> > mn;
        priority_queue < pis > mx;
        
        for(int i=1; i<=n; i++) {
            mn.push(make_pair(i, to_string(i)));
            mx.push(make_pair(i, to_string(i)));
        }
        
        while(mn.size() != 1) {
            int tot = mn.size();
            
            priority_queue < pis, vector<pis>, greater<pis> > tmn;
            priority_queue < pis > tmx;
            
            while(mn.size() > tot/2) {
                string lft = mn.top().second;
                string rgt = mx.top().second;
                
                tmn.push(make_pair(mn.top().first, "(" + lft + "," + rgt + ")"));
                tmx.push(make_pair(mn.top().first, "(" + lft + "," + rgt + ")"));
                
                mn.pop();
                mx.pop();
            }
            
            while(mn.size()) mn.pop();
            while(mx.size()) mx.pop();
            
            while(tmn.size()) {
                mn.push(tmn.top());
                tmn.pop();
            }
            
            while(tmx.size()) {
                mx.push(tmx.top());
                tmx.pop();
            }
        }
                    
        return mn.top().second;
    }
};