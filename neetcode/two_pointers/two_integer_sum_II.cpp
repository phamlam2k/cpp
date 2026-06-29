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
    int n, target;

    cin >> n >> target;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int total = numbers[left] + numbers[right];

        if (total == target) {
            cout << left + 1 << " " << right + 1 << endl;
            return;
        };

        if(total < target) {
            left++;
        } else if (total > target) {
            right--;
        }
    }

    cout << -1 << " " << -1 << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}