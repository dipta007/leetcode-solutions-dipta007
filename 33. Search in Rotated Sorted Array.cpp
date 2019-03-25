class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low < high)
        {
            int mid = (low + high) >> 1;

            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        int ind = low;
        if (ind >= nums.size())
            ind = 0;

        low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int rm = (ind + mid) % nums.size();

            if (nums[rm] > target)
                high = mid - 1;
            else if (nums[rm] < target)
                low = mid + 1;
            else
                return rm;
        }

        return -1;
    }
};