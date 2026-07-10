#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;
    
    cin >> n;

    if (n <= 1) {
        cout << 0;

        return;
    }

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int farthest = 0;
    int currentEnd = 0;
    int jump = 0;

    for (int i = 0; i < n; i++) {
        farthest = max(farthest, i + arr[i]);

        if (i == currentEnd) {
            jump++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) {
                break;
            }
        }
    } 

    cout << jump;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}