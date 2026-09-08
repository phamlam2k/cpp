#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    int n, target;

    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            cout << true;

            return;
        }

        if (nums[mid] < target)
        {
            if (nums[left] <= nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if (nums[left] <= nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    cout << false;
}

signed main()
{
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}