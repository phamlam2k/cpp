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
    int m, n, target;

    cin >> m >> n >> target;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }


    int top = 0;
    int bot = m - 1;
    int targetRow = -1;
    
    while (top <= bot) {
        int mid = top + (bot - top) / 2;
        
        if (target < matrix[mid][0]) {
            bot = mid - 1;
        } 
        else if (target > matrix[mid][n - 1]) {
            top = mid + 1;
        } 
        else {
            targetRow = mid;
            break;
        }
    }
    
    // Nếu duyệt xong mà không tìm thấy hàng nào phù hợp
    if (targetRow == -1) {
        cout << false;
        return;
    }
    
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        if (matrix[targetRow][mid] == target) {
            cout << true;

            return;
        }

        if (matrix[targetRow][mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << false;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}