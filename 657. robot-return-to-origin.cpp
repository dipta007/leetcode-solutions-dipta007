class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(int i = 0; i < moves.size(); i++)
        {
            char ch = moves[i];
            if(ch=='L') x--;
            else if(ch=='R') x++;
            else if(ch=='U') y++;
            else y--;
        }
        
        if(x==0 && y==0) return true;
        return false;
    }
};