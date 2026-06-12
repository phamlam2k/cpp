#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<vector<int>> arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            swap(arr[i][left], arr[i][right]);

            left++; right--;
        }
    }

    int num = 4;
    int right = n - 1;

    for (int i = 0; i < n; i++) {
        int v = n - 1;
        while (i < v) {
            int idx = 0;
        }
    }
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}