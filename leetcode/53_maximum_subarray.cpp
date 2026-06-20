#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mx = arr[0];
    int sum = arr[0];

    for (int i = 1; i < n; i++) {
        sum = max(sum + arr[i], arr[i] + arr[i - 1]);
        int selected = max(sum, arr[i]);

        mx = max(mx, selected);
    }
    
    cout << mx;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}