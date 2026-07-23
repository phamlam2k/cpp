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

    vector<int> nums1(n);
    vector<int> nums2(m);

    
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    
    int right = n + m - 1;
    int midx = m - 1;
    int nidx = n - 1;

    while (nidx >= 0) {
        if (midx >= 0 && nums1[midx] < nums2[nidx]) {
            nums1[right] = nums2[nidx];
            nidx--;
        } else {
            nums1[right] = nums1[midx];
            midx--;
        }
        right--;
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