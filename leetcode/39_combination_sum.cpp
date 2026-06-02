#include <iostream>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Hàm Backtracking chuẩn
void backtracking(vector<int>& arr, int target, int idx, vector<int>& choose, vector<vector<int>>& ans) {
    // 1. Điều kiện dừng thành công
    if (target == 0) {
        ans.push_back(choose);
        return;
    }

    // 2. Điều kiện dừng thất bại (vượt quá tổng)
    if (target < 0) {
        return;
    }

    // 3. Vòng lặp duyệt các nhánh
    for (int i = idx; i < arr.size(); i++) {
        // BƯỚC 1: Chọn (DO)
        choose.push_back(arr[i]);

        // BƯỚC 2: Gọi đệ quy (RECURSE)
        // Vì bài toán cho phép dùng lại 1 số nhiều lần, ta truyền tiếp 'i' thay vì 'i + 1'
        backtracking(arr, target - arr[i], i, choose, ans);

        // BƯỚC 3: Hoàn tác (UNDO) - Bắt buộc phải có
        choose.pop_back();
    }
}

void solve() {
    int n, target;
    if (!(cin >> n >> target)) return;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans;
    vector<int> choose;

    backtracking(arr, target, 0, choose, ans);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout <<  endl;
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