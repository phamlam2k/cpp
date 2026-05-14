#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

map<char, string> mp;

void init() {
    mp['2'] = "abc";
    mp['3'] = "def"; 
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
}

void dequy(vector<string> &ans_str, string str, int len, int idx, string ans) {
    if (idx >= len) {
        ans_str.push_back(ans);
        return;
    }

    string str2 = mp[str[idx]];

    int check_len = str2.length();

    for (int i = 0; i < check_len; i++) {
        string str3 = ans;
        dequy(ans_str, str, len, idx + 1, str3 += str2[i]);
    }
}
 
void solve() {
    init();

    string str;

    cin >> str;

    vector<string> ans_str;

    int len = str.length();

    dequy(ans_str, str, len, 0, "");

    for (int i = 0; i < ans_str.size(); i++) {
        cout << ans_str[i] << " ";
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