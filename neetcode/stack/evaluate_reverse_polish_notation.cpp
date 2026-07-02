#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<string> tokens(n);

    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    stack<int> stack;

    for (const string& c : tokens) {
        if (c == "+") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b + a);
        } else if (c == "-") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b - a);
        } else if (c == "*") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b * a);
        } else if (c == "/") {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            stack.push(b / a);
        } else {
            stack.push(stoi(c));
        }
    }
    
    cout << stack.top();
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}