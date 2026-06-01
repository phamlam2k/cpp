#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int searchRotatedSortedArray(vector<int> &arr, int left, int right, int target) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    
}

void solve() {
    
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}