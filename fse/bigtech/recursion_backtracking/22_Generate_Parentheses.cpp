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

void backtracking(vector<string> &ans, string &str, int cnt1, int cnt2, int n)
{
    if (cnt1 == n && cnt2 == n)
    {
        ans.push_back(str);

        return;
    }

    if (cnt1 < n)
    {
        str += '(';

        backtracking(ans, str, cnt1 + 1, cnt2, n);

        str.pop_back();
    }

    if (cnt1 > cnt2)
    {
        str += ')';

        backtracking(ans, str, cnt1, cnt2 + 1, n);

        str.pop_back();
    }
}

void solve()
{
    int n;

    cin >> n;

    vector<string> ans;

    string str = "";
    backtracking(ans, str, 0, 0, n);

    for (string x : ans)
    {
        cout << x << " ";
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