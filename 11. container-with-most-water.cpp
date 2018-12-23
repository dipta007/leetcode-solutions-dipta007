const int MX = 1e6+4;
int high[MX];
int arr[MX];

class Solution {
public:
    int maxArea(vector<int>& height) {
        memset(high, -1, sizeof high);
        memset(arr, -1, sizeof arr);
        for(int i=height.size()-1; i>=0; i--)
        {
            if(high[ height[i] ] == -1) 
                high[ height[i] ] = i;
            arr[ height[i] ] = i;
        }
        
        
        
        int maxy = 0, mini = MX;
        for(int i=MX-4; i>=0; i--)
        {
            maxy = max(maxy, high[i]);
            high[i] = maxy;
            
            if(arr[i] == -1) continue;
            mini = min(mini, arr[i]);
            arr[i] = mini;
        }
        
        int ans = 0;
        for(int i=0; i<height.size(); i++)
        {
            int l = arr[ height[i] ];
            int r = high [ height[i] ];
            
            //cout << l << " " << r << " " << height[i] << endl;
            if(l==r) continue;
            
            ans = max(ans, (r-l)*height[i] );
        }
        
        return ans;
    }
};