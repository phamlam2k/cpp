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

int partition(vector<string> &strNums, int left, int right)
{
    int mid = left + (right - left) / 2;

    int i = left - 1;
    int j = right + 1;
    string pivot = strNums[mid];

    while (1)
    {
        do
        {
            i++;
        } while (strNums[i] + pivot > pivot + strNums[i]);

        do
        {
            j--;
        } while (strNums[j] + pivot < pivot + strNums[j]);

        if (i < j)
        {
            swap(strNums[i], strNums[j]);
        }
        else
        {
            break;
        }
    }

    return j;
}

void quicksort(vector<string> &strNums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int p = partition(strNums, left, right);

    quicksort(strNums, left, p);
    quicksort(strNums, p + 1, right);
}

void solve()
{
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<string> strNums(n);

    for (int i = 0; i < n; i++)
    {
        strNums[i] = to_string(nums[i]);
    }

    quicksort(strNums, 0, n - 1);

    string ans;

    for (int i = 0; i < n; i++)
    {
        ans += strNums[i];
    }

    cout << ans;
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