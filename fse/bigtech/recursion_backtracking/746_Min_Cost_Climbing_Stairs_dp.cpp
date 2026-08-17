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

    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int prev1 = cost[0];
    int prev2 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int temp = prev1;

        prev1 = prev2;
        prev2 = cost[i] + min(temp, prev2);
    }

    cout << min(prev1, prev2);
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