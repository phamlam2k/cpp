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

unordered_map<int, int> memos;

int backtracking(vector<int> &cost, int idx, int n)
{
    if (idx >= n)
    {
        return 0;
    }

    if (memos.count(idx))
    {
        return memos[idx];
    }

    int sum1 = backtracking(cost, idx + 1, n);

    int sum2 = backtracking(cost, idx + 2, n);

    memos[idx] = cost[idx] + min(sum1, sum2);

    return memos[idx];
}

void solve()
{
    int n;

    cin >> n;

    vector<int> cost(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int ans = backtracking(cost, 0, n);

    cout << min(ans, memos[1]);
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