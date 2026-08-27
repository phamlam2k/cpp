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

int partition(vector<pair<char, int>> &p, int left, int right)
{
    int mid = left + (right - left) / 2;

    int i = left - 1;
    int j = right + 1;

    int pivot = p[mid].second;

    while (1)
    {
        do
        {
            i++;
        } while (p[i].second > pivot);

        do
        {
            j--;
        } while (p[j].second < pivot);

        if (i < j)
        {
            swap(p[i], p[j]);
        }
        else
        {
            break;
        }
    }

    return j;
}

void quicksort(vector<pair<char, int>> &p, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int part = partition(p, left, right);

    quicksort(p, left, part);
    quicksort(p, part + 1, right);
}

void solve()
{
    string str;

    cin >> str;

    int freq[128] = {0};
    int len = str.size();

    for (int i = 0; i < len; i++)
    {
        freq[str[i]]++;
    }

    vector<pair<char, int>> p;

    for (int i = 0; i <= 128; i++)
    {
        if (freq[i] > 0)
        {
            char c = i;

            p.push_back({c, freq[i]});
        }
    }

    int len_p = p.size();

    quicksort(p, 0, len_p - 1);

    string ans = "";

    for (int i = 0; i < len_p; i++)
    {
        for (int j = 0; j < p[i].second; j++)
        {
            ans.push_back(p[i].first);
        }
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