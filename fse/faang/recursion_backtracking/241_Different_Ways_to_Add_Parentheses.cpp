#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <cctype>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int expression(int x, int y, char exp)
{
    if (exp == '-')
        return x - y;
    else if (exp == '+')
        return x + y;
    else if (exp == '/')
        return x / y;
    else if (exp == '*')
        return x * y;

    return 0;
}

vector<int> dfs(string exp)
{
    int n = exp.size();

    vector<int> result;
    bool isNumber = true;

    for (int i = 0; i < n; i++)
    {
        char ch = exp[i];

        if (!isdigit(ch))
        {
            isNumber = false;

            vector<int> left = dfs(exp.substr(0, i));

            vector<int> right = dfs(exp.substr(i + 1));

            for (int x : left)
            {
                for (int y : right)
                {
                    int cal = expression(x, y, ch);
                    result.push_back(cal);
                }
            }
        }
    }

    if (isNumber)
    {
        result.push_back(stoll(exp));
    }

    return result;
}

void solve()
{
    string exp;

    cin >> exp;

    vector<int> ans = dfs(exp);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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