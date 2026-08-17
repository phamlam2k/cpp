#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int minusCal(int a, int b)
{
    return a - b;
}

int divide(int a, int b)
{
    return a / b;
}

int multiply(int a, int b)
{
    return a * b;
}

void solve()
{
    int n;

    cin >> n;

    vector<string> tokens(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tokens[i];
    }

    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "/")
        {
            st.push(tokens[i]);

            continue;
        }

        string second = st.top();
        st.pop();
        string first = st.top();
        st.pop();

        int num1 = stoll(first);
        int num2 = stoll(second);
        int num = 0;

        if (tokens[i] == "+")
        {
            num = add(num1, num2);
        }
        else if (tokens[i] == "-")
        {
            num = minusCal(num1, num2);
        }
        else if (tokens[i] == "/")
        {
            num = divide(num1, num2);
        }
        else
        {
            num = multiply(num1, num2);
        }

        st.push(to_string(num));
    }

    cout << st.top();
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