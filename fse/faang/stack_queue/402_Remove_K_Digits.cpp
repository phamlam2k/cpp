#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <deque>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    string num;
    int k;

    cin >> num >> k;

    string str;

    int len = num.length();

    for (int i = 0; i < len; i++)
    {
        while (str.size() && str.back() > num[i] && k)
        {
            str.pop_back();
            k--;
        }

        if (str.size() || num[i] != '0')
        {
            str += num[i];
        }
    }

    while (str.size() && k)
    {
        k--;
        str.pop_back();
    }

    cout << str;
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