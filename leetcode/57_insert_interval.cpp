#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// This one is the same as leetcode/56_merged_interval.cpp, but I have removed the compareArr function and used the default sort function instead. The compareArr function was unnecessary since the default sort function can handle sorting of vectors of vectors based on the first element of each vector.
void solve() {
    int n;
    
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    res.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        vector<int>& selected = res.back();

        int x = selected[1];
        int y = arr[i][0];

        if (x >= y) {
            selected[1] = max(x, arr[i][1]);
        } else {
            res.push_back(arr[i]);
        }
    }

    int len = res.size();

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 2; j++) {
            cout << res[i][j] << " ";
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