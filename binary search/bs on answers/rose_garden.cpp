#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    bool possible(vector<int> &arr, int day, int m, int k)
    {

        int n = arr.size(); // size of the array

        int cnt = 0;

        int noOfB = 0;

        // count the number of bouquets:

        for (int i = 0; i < n; i++)
        {

            if (arr[i] <= day)
            {

                cnt++;
            }

            else
            {

                noOfB += (cnt / k);

                cnt = 0;
            }
        }

        noOfB += (cnt / k);

        return noOfB >= m;
    }

    int roseGarden(vector<int> arr, int k, int m)

    {

        int n = arr.size();

        if (n < (m * k))

        {

            return -1;
        }

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < n; i++)
        {

            mini = min(mini, arr[i]);

            maxi = max(maxi, arr[i]);
        }

        int low = mini, high = maxi;

        while (low <= high)

        {

            int mid = (low + high) / 2;

            if (possible(arr, mid, m, k))
            {

                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return low;
    }
};
int main()
{
    vector<int> arr = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    int k = 3;
    int m = 2;
    solution s;
    cout << s.roseGarden(arr, k, m);
    return 0;
}