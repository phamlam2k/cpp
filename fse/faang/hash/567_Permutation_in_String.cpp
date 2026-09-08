#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <tuple>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    string s1, s2;

    cin >> s1 >> s2;

    int n1 = s1.size();
    int n2 = s2.size();

    vector<int> h1(28, 0);

    for (int i = 0; i < n1; i++)
    {
        int index = s1[i] - 'a';
        h1[index]++;
    }

    vector<int> h2(28, 0);

    for (int i = 0; i < n1; i++)
    {
        int index = s2[i] - 'a';
        h2[index]++;
    }

    for (int i = 0; i <= n2 - n1; i++)
    {
        if (h1 == h2)
        {
            cout << true;

            return;
        }

        if (i < n2 - n1)
        {
            int index = s2[i] - 'a';
            int indexN = s2[i + n1] - 'a';

            h2[index]--;
            h2[indexN]++;
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