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

unordered_map<int, int> mp;
int recursion(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    if (mp.count(n))
    {
        return mp[n];
    }

    int res = recursion(n - 1) + recursion(n - 2);

    mp[n] = res;

    return mp[n];
}

void solve()
{
    int n;

    cin >> n;

    cout << recursion(n);
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