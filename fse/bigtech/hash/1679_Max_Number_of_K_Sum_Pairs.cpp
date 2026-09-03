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

    unordered_map<int, int> mp;

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > k)
            continue;

        int target = k - nums[i];

        if (mp[nums[i]])
        {
            cnt++;
            mp[nums[i]]--;

            continue;
        }

        mp[target] = mp[target] ? mp[target] + 1 : 1;
    }

    cout << cnt;
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