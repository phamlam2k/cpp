#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int current = 1;
set<int> mySet;

int popSmallest() {
    if (!mySet.empty()) {
        int res = *mySet.begin();
        mySet.erase(res);
        return res;
    }

    int res = current;
    current++;

    return res;
}

void addBack(int num) {
    if (num < current) {
        mySet.insert(num);
    }
}

void solve() {
    // Test ở đây
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}