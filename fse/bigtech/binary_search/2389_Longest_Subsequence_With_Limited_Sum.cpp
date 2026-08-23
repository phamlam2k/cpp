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
    int n, m;

    cin >> n >> m;

    vector<int> nums(n);
    vector<int> queries(m);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> queries[i];
    }

    sort(nums.begin(), nums.end());

    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
    }

    vector<int> ans(m, 0);

    for (int i = 0; i < m; i++)
    {
        auto it = upper_bound(nums.begin(), nums.end(), queries[i]);

        int result = distance(nums.begin(), it);

        ans[i] = result;
    }

    for (int i = 0; i < m; i++)
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