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
    int num;

    cin >> num;

    int left = 1;
    int right = num;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid * mid == num)
        {
            cout << true;

            return;
        }

        if (mid * mid < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << false;
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