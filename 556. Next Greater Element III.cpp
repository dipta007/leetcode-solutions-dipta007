class Solution
{
  public:
    int nextGreaterElement(int n)
    {
        string st;
        while (n)
        {
            int kk = n % 10;
            n /= 10;

            st += (kk + '0');
        }

        reverse(st.begin(), st.end());

        int ind = -1;
        for (int i = 0; i < st.size() - 1; i++)
        {
            if (st[i] < st[i + 1])
            {
                ind = i;
            }
        }

        if (ind < 0)
            return -1;

        int mn, mnd = ind + 1;
        mn = st[ind + 1];
        for (int i = ind + 1; i < st.size(); i++)
        {
            if (st[i] < mn && st[i] > st[ind])
            {
                mn = st[i];
                mnd = i;
            }
        }

        swap(st[ind], st[mnd]);
        // cout << st << " " << ind << " " << mnd << endl;

        sort(st.begin() + ind + 1, st.end());

        stringstream ss(st);
        long long x;
        ss >> x;

        if (x > INT_MAX)
            x = -1;
        return x;
    }
};