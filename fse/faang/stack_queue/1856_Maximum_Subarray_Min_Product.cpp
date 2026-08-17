#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> pre_sums(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        pre_sums[i + 1] = pre_sums[i] + nums[i];
    }

    vector<int> left_bounds(n, -1);
    vector<int> right_bounds(n, n);

    stack<int> minStack;

    for (int i = 0; i < n; i++)
    {
        while (!minStack.empty() && nums[minStack.top()] >= nums[i])
        {
            minStack.pop();
        }

        if (!minStack.empty())
        {
            left_bounds[i] = minStack.top();
        }

        minStack.push(i);
    }

    while (!minStack.empty())
    {
        minStack.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!minStack.empty() && nums[minStack.top()] >= nums[i])
        {
            minStack.pop();
        }

        if (!minStack.empty())
        {
            right_bounds[i] = minStack.top();
        }
        minStack.push(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int current_sum = pre_sums[right_bounds[i]] - pre_sums[left_bounds[i] + 1];

        ans = max(current_sum * nums[i], ans);
    }

    int MOD = 1e9 + 7;

    cout << ans % MOD;
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