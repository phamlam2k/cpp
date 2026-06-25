#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string encode (vector<string>& strs) {
    int len = strs.size();

    string str;
    
    for (int i = 0; i < len; i++) {
        str += strs[i];

        if (i < len - 1) {
            str += "~";
        }
    }

    return str;
}

vector<string> decode(string s) {
    vector<string> ans;
    int len = s.length();
    string str = "";

    for (int i = 0; i < len; i++) {
        if (s[i] == '~') {
            ans.push_back(str);
            str = "";
        } else {
            str += s[i];
        }
    }

    return ans;
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