class Solution
{
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    vector<int> ret;
    if (matrix.size() == 0)
      return ret;

    int ux, ly, dx, ry;
    ux = 0, dx = matrix.size() - 1;
    ly = 0, ry = matrix[0].size() - 1;

    for (int i = 0;; i = (i + 1) % 4)
    {
      int kk = ret.size();
      if (i == 0)
      {
        for (int i = ly; i <= ry; i++)
        {
          ret.push_back(matrix[ux][i]);
        }
        ux++;
      }
      else if (i == 1)
      {
        for (int i = ux; i <= dx; i++)
        {
          ret.push_back(matrix[i][ry]);
        }
        ry--;
      }
      else if (i == 2)
      {
        for (int i = ry; i >= ly; i--)
        {
          ret.push_back(matrix[dx][i]);
        }
        dx--;
      }
      else
      {
        for (int i = dx; i >= ux; i--)
        {
          ret.push_back(matrix[i][ly]);
        }
        ly++;
      }
      if (kk == ret.size())
        break;
    }

    return ret;
  }
};