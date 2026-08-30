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

void countingSort(vector<int> &nums, int exp)
{
    int len = nums.size();

    vector<int> cnt(10, 0);
    vector<int> output(len, 0);

    for (int i = 0; i < len; i++)
    {
        int num = (nums[i] / exp) % 10;

        cnt[num]++;
    }

    for (int i = 1; i < 10; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    for (int i = len - 1; i >= 0; i--)
    {
        int num = (nums[i] / exp) % 10;
        output[--cnt[num]] = nums[i];
    }

    nums = output;
}

void radixsort(vector<int> &nums, int max_element)
{
    for (int exp = 1; max_element / exp > 0; exp *= 10)
    {
        countingSort(nums, exp);
    }
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

    int max_element = 0;

    for (int i = 0; i < n; i++)
    {
        max_element = max(max_element, nums[i]);
    }

    radixsort(nums, max_element);

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