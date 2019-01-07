class Solution {
public:
    int candy(vector<int>& ratings) {
        int rgt[ratings.size() + 4];
        for(int i=0; i<ratings.size(); i++) rgt[i] = 0;
        for(int i=(int)ratings.size()-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                rgt[i] = rgt[i+1] + 1;
            }
        }
        
        int sum = max(1, rgt[0] + 1);
        int left = 0;
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]) {
                left = left + 1;
            } else {
                left = 0;
            }
            
            sum += max(rgt[i]+1, left+1);
        }
        
        return sum;
    }
};