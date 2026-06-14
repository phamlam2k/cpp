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

    vector<vector<int>> arr(n, vector<int>(n));

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

    int num = n - 1;
    int right = n - 1;

    for (int i = 0; i < n - 1; i++) {
        int v = n - 1;
        int idx = 0;
        
        while (i < v) {
            swap(arr[i][idx], arr[v][right]);
            
            idx++;
            v--;
        }

        right--;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }

        cout << endl;
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