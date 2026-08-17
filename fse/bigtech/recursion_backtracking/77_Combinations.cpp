#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void recursion(vector<vector<int>> &ans, vector<int> &num, int n, int k, int idx, int limit)
{
    if (num.size() == k)
    {
        ans.push_back(num);

        return;
    }

    for (int i = idx; i <= n - k + limit; i++)
    {
        num.push_back(i);

        recursion(ans, num, n, k, i + 1, limit + 1);

        num.pop_back();
    }
}

void solve()
{
    int n, k;

    cin >> n >> k;

    vector<vector<int>> ans;
    vector<int> num;

    recursion(ans, num, n, k, 1, 1);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }

        cout << " ";
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