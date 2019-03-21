int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
class Solution
{

    int tt;

    bool dfs(int x, int y, int in, string &w, vector<vector<char>> &brd, vector<vector<int>> &vis)
    {
        if (in >= w.size())
            return 1;
        vis[x][y] = tt;

        int ret = 0;
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (X >= 0 && Y >= 0 && X < brd.size() && Y < brd[X].size() && brd[X][Y] == w[in] && vis[X][Y] != tt)
            {
                ret = ret || dfs(X, Y, in + 1, w, brd, vis);
            }
        }

        vis[x][y]--;
        return ret;
    }

  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.size() == 0)
            return true;

        vector<vector<int>> vis;
        vis.assign(board.size(), vector<int>());
        for (int i = 0; i < vis.size(); i++)
        {
            vis[i].assign(board[i].size(), 0);
        }
        tt = 0;

        int ret = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    tt++;
                    ret = ret || dfs(i, j, 1, word, board, vis);
                }
            }
        }

        return ret;
    }
};