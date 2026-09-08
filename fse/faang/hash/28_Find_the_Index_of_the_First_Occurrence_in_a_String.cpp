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

int MOD = 1e9 + 7;

void solve()
{
    string haystack, needle;

    cin >> haystack >> needle;

    int hsize = haystack.size();
    int nsize = needle.size();

    if (nsize > hsize)
    {
        cout << -1;

        return;
    }

    int K = 2;

    int high_power = 1;
    for (int i = 0; i < nsize - 1; i++)
    {
        high_power = (high_power * K) % MOD;
    }

    int hash_n = 0;
    for (int i = 0; i < nsize; i++)
    {
        hash_n = (hash_n * K + (int)needle[i]) % MOD;
    }

    int hash_h = 0;
    for (int i = 0; i < nsize; i++)
    {
        hash_h = (hash_h * K + (int)haystack[i]) % MOD;
    }

    for (int i = 0; i <= hsize - nsize; i++)
    {
        if (hash_n == hash_h)
        {
            if (haystack.compare(i, nsize, needle) == 0)
            {
                cout << i;

                return;
            }
        }

        if (i < hsize - nsize)
        {
            hash_h = (hash_h - ((int)haystack[i] * high_power % MOD) + MOD) % MOD;
            hash_h = (K * hash_h + (int)haystack[i + nsize]) % MOD;
        }
    }

    cout << -1;
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