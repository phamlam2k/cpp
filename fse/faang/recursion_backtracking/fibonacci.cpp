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

int f(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }

    if (mp.count(n))
    {
        return mp[n];
    }

    return f(n - 1) + f(n - 2);
}

void solve()
{
    int n;

    cin >> n;

    cout << f(n);
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