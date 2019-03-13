class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int low = 0, high = nums1.size();
        int px, py;
        int tot = (nums1.size() + nums2.size() + 1) / 2;

        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        double res;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            // cout << low << " " << mid << " " << high << " " << tot << endl;

            int px = mid;
            int py = tot - mid;

            int px1, px2, py1, py2;

            if (px == 0)
                px1 = INT_MIN;
            else
                px1 = nums1[px - 1];
            px2 = nums1[px];

            if (py == 0)
                py1 = INT_MIN;
            else
                py1 = nums2[py - 1];
            py2 = nums2[py];

            // cout << px1 << " " << px2 << endl;
            // cout << py1 << " " << py2 << endl;

            if (px1 <= py2 && py1 <= px2)
            {
                if ((nums1.size() + nums2.size()) % 2 == 0)
                {
                    cout << "Ad" << endl;
                    res = (max(px1, py1) + min(px2, py2)) / 2.0;
                }
                else
                {
                    res = max(px1, py1);
                }
                break;
            }
            else if (px1 >= py2)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};