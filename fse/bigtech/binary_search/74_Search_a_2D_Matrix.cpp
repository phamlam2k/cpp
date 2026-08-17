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
    int n, m, target;

    cin >> n >> m >> target;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int left = 0;
    int right = n - 1;
    int idx = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int num = matrix[mid][m - 1];

        if (num == target)
        {
            cout << true;

            return;
        }

        if (num < target)
        {
            left = mid + 1;
        }
        else
        {
            idx = mid;
            right = mid - 1;
        }
    }

    if (idx == -1)
    {
        cout << false;

        return;
    }

    left = 0;
    right = m - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int num = matrix[idx][mid];

        if (num == target)
        {
            cout << true;

            return;
        }

        if (num < target)
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