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

unordered_map<char, vector<char>> mp;

void init()
{
    mp.insert({'2', {'a', 'b', 'c'}});
    mp.insert({'3', {'d', 'e', 'f'}});
    mp.insert({'4', {'g', 'h', 'i'}});
    mp.insert({'5', {'j', 'k', 'l'}});
    mp.insert({'6', {'m', 'n', 'o'}});
    mp.insert({'7', {'p', 'q', 'r', 's'}});
    mp.insert({'8', {'t', 'u', 'v'}});
    mp.insert({'9', {'w', 'x', 'y', 'z'}});
}

void backtracking(vector<string> &ans, string digits, string str, int idx, int digits_len)
{
    if (idx == digits_len)
    {
        ans.push_back(str);

        return;
    }

    vector<char> characters = mp[digits[idx]];

    int len = characters.size();

    for (int i = 0; i < len; i++)
    {
        str += characters[i];

        backtracking(ans, digits, str, idx + 1, digits_len);

        str.pop_back();
    }
}

void solve()
{
    init();
    string digits;

    cin >> digits;

    vector<string> ans;

    backtracking(ans, digits, "", 0, digits.size());

    for (string x : ans)
    {
        cout << x << " ";
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