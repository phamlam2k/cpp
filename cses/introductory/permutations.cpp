#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    if (n == 1) {
        cout << 1;

        return;
    }
    
    queue<int> q;
    stack<int> ans;

    q.push(n);

    for (int i = n - 1; i > 0; i--) {
        if (ans.empty()) {
            ans.push(i);
        } else {
            if (ans.top() - i == 1) {
                q.push(i);
            } else {
                ans.push(i);
            }
        }
    }

    while (!q.empty())
    {
        int front = q.front();

        if (abs(ans.top() - front) > 1) {
            ans.push(front);
        }

        q.pop();
    }

    if (ans.size() != n) {
        cout << "NO SOLUTION";
        return;
    }

    int len = ans.size();

    vector<int> arr;

    while (!ans.empty())
    {
        int top = ans.top();

        arr.push_back(top);

        ans.pop();
    }

    for (int i = len - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}