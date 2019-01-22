class TicTacToe {
public:
    vector <vector <int> > v;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        v.assign(n, vector<int>());
        for(int i=0; i<n; i++) {
            v[i].assign(n, 0);
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        v[row][col] = player;
        int flg = 1;
        for(int i=0; i<v.size(); i++) {
            if(v[row][i] != player) {
                flg = 0;
                break;
            }
        }
        if(flg) return player;
        
        flg = 1;
        for(int i=0; i<v.size(); i++) {
            if(v[i][col] != player) {
                flg = 0;
                break;
            }
        }
        if(flg) return player;
        
        if(row == col) {
            int flg = 1;
            for(int i=0, j=0; i<v.size(); i++, j++) {
                if(v[i][j] != player) {
                    flg = 0;
                    break;
                }
            }
            if(flg) return player;
        }
        
        if(abs(row - 0) == abs(col-(int)v.size()+1)) {
            flg = 1;
            for(int i=0, j=v.size()-1; j>=0; i++, j--) {
                if(v[i][j] != player) {
                    flg = 0;
                    break;
                }
            }
            if(flg) return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */