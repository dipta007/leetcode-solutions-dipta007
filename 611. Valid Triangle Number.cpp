class Solution
{
  public:
    int triangleNumber(vector<int> &nums)
    {
        int ret = 0;
        int k = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++)
        {
            int k = i + 2;
            for (int j = i + 1; j < (int)nums.size() - 1 && nums[i] != 0; j++)
            {
                while (k < nums.size() && nums[i] + nums[j] > nums[k])
                    k++;

                ret += (k - j - 1);
            }
        }

        return ret;
    }
};