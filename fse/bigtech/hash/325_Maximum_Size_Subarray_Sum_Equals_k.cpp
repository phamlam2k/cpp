#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    int n, k;

    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int max_length = 0;

    unordered_map<int, int> mp;
    mp[0] = -1;
    int presum = 0;

    for (int i = 0; i < n; i++)
    {
        presum += nums[i];

        if (mp.count(presum - k))
        {
            max_length = max(max_length, i - mp[presum - k]);
        }

        if (!mp.count(presum))
        {
            mp[presum] = i;
        }
    }

    cout << max_length;
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