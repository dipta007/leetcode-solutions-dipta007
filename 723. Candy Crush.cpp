class Solution
{
    bool stable(vector<vector<int>> &b)
    {
        for (int i = 0; i < b[0].size(); i++)
        {
            int flg = 0;
            for (int j = 0; j < b.size(); j++)
            {
                if (b[j][i])
                    flg = 1;
                if (flg && b[j][i] == 0)
                    return false;
            }
        }
        return true;
    }

    bool cross(vector<vector<int>> &b)
    {
        vector<vector<int>> mark(b.size(), vector<int>());
        for (int i = 0; i < b.size(); i++)
            mark[i].assign(b[i].size(), 0);

        int flg = 0;
        for (int i = 0; i < b.size(); i++)
        {
            for (int j = 0; j <= (int)b[i].size() - 3; j++)
            {

                // cout << i << " " << j << " " << b[i][j] << endl;
                if (b[i][j] && b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
                {
                    mark[i][j + 0] = 1;
                    mark[i][j + 1] = 1;
                    mark[i][j + 2] = 1;

                    flg = 1;

                    // cout << "r " << i << " " << j << endl;
                }
            }
        }

        for (int i = 0; i < b[0].size(); i++)
        {
            for (int j = 0; j <= (int)b.size() - 3; j++)
            {
                if (b[j][i] && b[j][i] == b[j + 1][i] && b[j][i] == b[j + 2][i])
                {
                    mark[j + 0][i] = 1;
                    mark[j + 1][i] = 1;
                    mark[j + 2][i] = 1;

                    flg = 1;

                    // cout << "c " << i << " " << j << endl;
                }
            }
        }

        for (int i = 0; i < b[0].size(); i++)
        {
            int w = b.size() - 1;
            for (int j = b.size() - 1; j >= 0; j--)
            {
                if (mark[j][i] == 0)
                {
                    b[w][i] = b[j][i];
                    w--;
                }
            }

            while (w >= 0)
            {
                b[w][i] = 0;
                w--;
            }
        }

        return flg;
    }

  public:
    vector<vector<int>> candyCrush(vector<vector<int>> &board)
    {
        if (board.size() == 0)
            return board;
        cout << cross(board) << endl;

        while (cross(board) == 1)
        {
        }

        return board;
    }
};