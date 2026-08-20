#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <numeric>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

bool dfs(vector<int> &matchsticks, vector<int> &sides, int idx, int target, int n)
{
    if (idx == n)
    {
        return true;
    }

    for (int i = 0; i < 4; i++)
    {
        if (sides[i] + matchsticks[idx] > target)
        {
            continue;
        }

        sides[i] += matchsticks[idx];

        if (dfs(matchsticks, sides, idx + 1, target, n))
        {
            return true;
        }

        sides[i] -= matchsticks[idx];
    }

    return false;
}

void solve()
{
    int n;

    cin >> n;

    vector<int> matchsticks(n);

    for (int i = 0; i < n; i++)
    {
        cin >> matchsticks[i];
    }

    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

    if (sum % 4 != 0)
    {
        cout << false;

        return;
    }

    int target = sum / 4;
    sort(matchsticks.rbegin(), matchsticks.rend());

    vector<int> sides(4, 0);

    bool check = dfs(matchsticks, sides, 0, target, n);

    cout << check;
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