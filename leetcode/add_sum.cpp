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
    string str1, str2;

    cin >> str1 >> str2;

    int i = str1.length() - 1;
    int j = str2.length() - 1;
    int carry = 0;
    string ans = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int digit1 = (i >= 0) ? str1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? str2[j--] - '0' : 0;

        int total = digit1 + digit2 + carry;
        ans += (char)((total % 2) + '0');
        carry = total / 2;
    }
    
    reverse(ans.begin(), ans.end());

    cout << ans;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}