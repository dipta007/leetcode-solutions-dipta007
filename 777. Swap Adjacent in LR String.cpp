class Solution {
public:
    bool canTransform(string start, string end) {
        for(int i=0; i<start.size(); i++) {
            if(start[i] != end[i]) {
                if(end[i] == 'L' && start[i] == 'X') {
                    int j = i;
                    while(j<start.size() && (end[j] == 'L' || start[j] != 'L')) j++;
                    if(j<start.size()) swap(start[j], start[i]);
                }
                else if(end[i] == 'R' && start[i] == 'X') {
                    int j = i;
                    while(j>=0 && (end[j] == 'R' || start[j] != 'R')) j--;
                    if(j >= 0) swap(start[j], start[i]);
                }
            }
            // cout << i << " " << start << " " << end << endl;
        }
        return start == end;
    }
};