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

int partition(vector<int> &nums, int l, int r)
{
    int mid = (l + r) / 2;

    int pivot = nums[mid];

    int i = l - 1;
    int j = r + 1;

    while (1)
    {
        do
        {
            ++i;
        } while (nums[i] < pivot && i <= r);

        do
        {
            --j;
        } while (nums[j] > pivot && j >= 0);

        if (i < j)
        {
            swap(nums[i], nums[j]);
        }
        else
        {
            break;
        }
    }

    return j;
}

void quicksort(vector<int> &nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int p = partition(nums, left, right);

    quicksort(nums, left, p);
    quicksort(nums, p + 1, right);
}

void solve()
{
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    quicksort(nums, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
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