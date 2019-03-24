class Solution
{
  public:
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        vector<vector<int>> ret;

        ret.assign(A.size(), vector<int>());
        for (int i = 0; i < ret.size(); i++)
        {
            ret[i].assign(B[0].size(), 0);
        }

        vector<vector<pair<int, int>>> ind;
        ind.assign(A.size(), vector<pair<int, int>>());

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                if (A[i][j])
                    ind[i].push_back(make_pair(A[i][j], j));
            }
        }

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < ind[i].size(); j++)
            {
                int c = ind[i][j].second;
                int v = ind[i][j].first;

                for (int k = 0; k < B[0].size(); k++)
                {
                    ret[i][k] += (v * B[c][k]);
                }
            }
        }

        return ret;
    }
};