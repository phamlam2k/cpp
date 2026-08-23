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

void dfs(vector<int> &nums, vector<vector<int>> &ans, vector<int> &result, int n, int index)
{
    if (index == n)
    {
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;

        result.push_back(nums[i]);

        dfs(nums, ans, result, n, i + 1);

        ans.push_back(result);

        result.pop_back();
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

    vector<vector<int>> ans;
    vector<int> result;

    ans.push_back({});

    dfs(nums, ans, result, n, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
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