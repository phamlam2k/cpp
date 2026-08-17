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

void backtracking(vector<int> &candidates, vector<vector<int>> &ans,
                  vector<int> &nums, int idx, int target, int n)
{
    if (target == 0)
    {
        ans.push_back(nums);

        return;
    }

    if (target < 0)
    {
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;

        nums.push_back(candidates[i]);

        backtracking(candidates, ans, nums, i + 1, target - candidates[i], n);

        nums.pop_back();
    }
}

void solve()
{
    int n, target;

    cin >> n >> target;

    vector<int> candidates(n);

    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> nums;

    backtracking(candidates, ans, nums, 0, target, n);
}

signed main()
{
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}