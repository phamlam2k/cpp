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

void flip(vector<int> &arr, int maxIndex)
{
    int i = 0;
    int j = maxIndex;

    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
}

void solve()
{
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int currentIndex = n - 1;
    vector<int> results;

    while (currentIndex)
    {
        int maxIndex = 0;

        for (int i = 0; i <= currentIndex; i++)
        {
            if (arr[i] > arr[maxIndex])
            {
                maxIndex = i;
            }
        }

        if (maxIndex != 0)
        {
            results.push_back(maxIndex + 1);
        }
        flip(arr, maxIndex);

        results.push_back(currentIndex + 1);
        flip(arr, currentIndex);

        currentIndex--;
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << " ";
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