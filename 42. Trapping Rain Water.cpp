class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int res = 0;
        int left = 0;
        while(height[left] == 0) left++;
        
        int now = height[left];
        int cnt = 0;
        for(int rgt=left+1; rgt < height.size(); rgt++) {
            if(height[rgt] < now) {
                cnt += (now - height[rgt]);
            }
            else {
                res += cnt;
                now = height[rgt];
                left = rgt;
                cnt = 0;
            }
        }
        
        if(cnt > 0) {
            int rgt = height.size()-1;
            while(height[rgt] == 0) rgt--;
            now = height[rgt];
            cnt = 0;
            for(int i=rgt-1; i>=left; i--) {
                if(height[i] < now) {
                    cnt += now - height[i];
                }
                else {
                    res += cnt;
                    now = height[i];
                    rgt = i;
                    cnt = 0;
                }
            }
        }
        return res;
    }
};