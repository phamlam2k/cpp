#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    int n;

    cin >> n;

    vector<vector<int>> board(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<unordered_set<int>> cols;
    vector<unordered_set<int>> rows;
    vector<vector<unordered_set<int>>> grids;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.') continue;
            
            int row = i / 3;
            int col = j / 3;

            if (cols[j].count(board[i][j]) || rows[i].count(board[i][j]) || grids[row][col].count(board[i][j])) {
                cout << false;

                return;
            }

            cols[j].insert(board[i][j]);
            rows[i].insert(board[i][j]);
            grids[row][col].insert(board[i][j]);
        }
    }

    cout << true;
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}