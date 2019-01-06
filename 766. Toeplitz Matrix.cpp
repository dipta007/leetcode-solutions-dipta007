class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int flg = 1;
        int r = matrix.size();
        int c = matrix[0].size();
        
        for(int rr=r-1, cc=0; rr>=0; rr--) {
            int val = matrix[rr][cc];
            for(int i=rr, j=cc; i<r && j<c; i++, j++) {
                if(matrix[i][j] != val) {
                    flg = 0;
                }
            }
        }
        
        for(int rr=0, cc=0; cc<c; cc++) {
            int val = matrix[rr][cc];
            for(int i=rr, j=cc; i<r && j<c; i++, j++) {
                if(matrix[i][j] != val) {
                    flg = 0;
                }
            }
        }
        
        return flg;
    }
};