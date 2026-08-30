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

// Counting Solution
// void solve()
// {
//     int n, k;

//     cin >> n >> k;

//     vector<int> nums(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }

//     int max_value = 0;
//     int OFFSET = 10000;
//     vector<int> cnt(20001, 0);

//     for (int i = 0; i < n; i++)
//     {
//         int offset_nums = nums[i] + OFFSET;
//         max_value = max(max_value, offset_nums);
//         cnt[offset_nums]++;
//     }

//     for (int i = max_value; i >= 0; i--)
//     {
//         k -= cnt[i];

//         if (k <= 0)
//         {
//             cout << i - OFFSET;

//             return;
//         }
//     }

//     cout << -1;
// }

int partition(vector<int> &nums, int left, int right)
{
    int pivot = left + rand() % (right - left + 1);
    int i = left - 1;
    int j = right + 1;

    int p = nums[pivot];

    while (1)
    {
        do
        {
            i++;
        } while (nums[i] < p);

        do
        {
            j--;
        } while (nums[j] > p);

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

// QuickSelect Solution
void quickSelect(vector<int> &nums, int left, int right, int target)
{
    if (left >= right)
    {
        return;
    }

    int p = partition(nums, left, right);

    if (target <= p)
    {
        quickSelect(nums, left, p, target);
    }
    else
    {
        quickSelect(nums, p + 1, right, target);
    }
}

void solve()
{
    int n, k;

    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target = n - k;

    quickSelect(nums, 0, n - 1, target);

    cout << nums[target];
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