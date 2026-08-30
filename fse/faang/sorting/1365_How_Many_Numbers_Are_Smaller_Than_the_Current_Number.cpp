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

    vector<int> cnt(max_element + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cnt[nums[i]]++;
    }

    for (int i = 1; i <= max_element; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            ans[i] = 0;
        }
        else
        {
            ans[i] = cnt[nums[i] - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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