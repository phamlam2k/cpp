#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string str;
    int numRows;

    cin >> str >> numRows;

    if (numRows == 1) {
        cout << str;
        
        return;
    }

    int len = str.length();

    vector<vector<char>> arr(numRows, vector<char>(len));

    int x = 0;
    int y = 0;

    pair<int, int> direct;

    for (int i = 0; i < len; i++) {
        arr[x][y] = str[i];

        if (x == 0) {            
            direct = { 1, 0 };
        }

        if (x == numRows - 1) {
            direct = { -1, 1 };
        }


        x += direct.first;
        y += direct.second;
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[i][j]) {
                cout << arr[i][j];
            }
        }
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