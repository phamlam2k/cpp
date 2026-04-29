#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 1; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int miss = 0;

    for (int i = 1; i <= n; i++) {
        if (i != arr[i]) {
            miss = i;
            break;
        }
    }

    cout << miss;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}