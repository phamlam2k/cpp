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
    int n, m;

    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int top = 0; int bottom = n - 1;
    int left = 0; int right = m - 1;
    vector<int> res;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            res.push_back(arr[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            res.push_back(arr[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                res.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res.push_back(arr[i][left]);
            }
            left++;
        }

    }

    int len = res.size();

    for (int i = 0; i < len; i++) {
        cout << res[i] << " ";
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