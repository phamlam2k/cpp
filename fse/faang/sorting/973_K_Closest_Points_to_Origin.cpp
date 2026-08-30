#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

inline int getDistSq(const vector<int> &p)
{
    return p[0] * p[0] + p[1] * p[1];
}

int partition(vector<vector<int>> &nums, int left, int right)
{
    int pivot = left + rand() % (right - left + 1);
    int i = left - 1;
    int j = right + 1;

    int p = getDistSq(nums[pivot]);

    while (1)
    {
        do
        {
            i++;
        } while (getDistSq(nums[i]) < p);

        do
        {
            j--;
        } while (getDistSq(nums[j]) > p);

        if (i < j)
        {
            swap(nums[i], nums[j]);
        }
        else
        {
            break;
        }
    }

    return j;
}

void quickselect(vector<vector<int>> &nums, int left, int right, int target)
{
    if (left >= right)
    {
        return;
    }

    int p = partition(nums, left, right);

    if (p <= target)
    {
        quickselect(nums, p + 1, right, target);
    }
    else
    {
        quickselect(nums, left, p, target);
    }
}

void solve()
{
    int n, k;

    cin >> n, k;

    vector<vector<int>> nums(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> nums[i][j];
        }
    }

    int target = k - 1;

    quickselect(nums, 0, n - 1, target);
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