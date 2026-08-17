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

stack<pair<int, int>> stocks;
int idx = 0;

int next(int price) {
    idx++;

    if (stocks.empty()) {
        stocks.push({ price, idx });
        return idx;
    }
    
    while (!stocks.empty() && stocks.top().first <= price) {
        stocks.pop();
    }

    int ans;

    if (stocks.empty()) {
        ans = idx;
    } else {
        ans = idx - stocks.top().second;
    }
    
    stocks.push({ price, idx });
    return ans;
}

void solve() {
    cout << next(100) << endl;
    cout << next(80) << endl;
    cout << next(60) << endl;
    cout << next(70) << endl;
    cout << next(60) << endl;
    cout << next(75) << endl;
    cout << next(85) << endl;

}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}