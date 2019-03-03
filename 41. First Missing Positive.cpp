class Solution
{
  public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                nums[i] = 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            while (x > 0 && x <= nums.size())
            {
                int tmp = x - 1;
                if (x == nums[x - 1])
                    x = -1;
                else
                    x = nums[x - 1];

                nums[tmp] = -1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};