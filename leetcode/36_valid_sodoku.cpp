#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n, m;

    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<unordered_set<int>> rows(n);
    vector<unordered_set<int>> cols(m);
    unordered_set<int> boxes[3][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1';
                int boxRow = i / 3;
                int boxCol = j / 3;

                if (rows[i].count(num) || cols[j].count(num) || boxes[boxRow][boxCol].count(num)) {
                    cout << "Invalid Sudoku" << endl;
                    return;
                }

                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxRow][boxCol].insert(num);
            }
        }
    }

    cout << "Valid Sudoku" << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}