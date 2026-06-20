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
    int n, k;

    cin >> n >> k;

    vector<int> fact(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    vector<int> digits;

    for (int i = 1; i <= n; i++) {
        digits.push_back(i); 
    } 

    k--;
    string result = "";

    for (int i = n; i > 0; i--) {
        int idx = k / fact[i - 1];

        result += char('0' + digits[idx]);
        
        digits.erase(digits.begin() + idx);

        k %= fact[i - 1];
    }

    cout << result;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}