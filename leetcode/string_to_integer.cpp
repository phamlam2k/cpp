#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string str;

    cin >> str;

    queue<char> q;

    int len = str.length();

    for (int i = 0; i < len; i++) {
        int c = (int)str[i];

        if (str[i] == ' ') {
            continue;
        }

        if (str[i] == '-') {
            if (q.empty()) {
                q.push(str[i]);
                continue;
            } else {
                break;
            }
        }

        if (str[i] == '+' && q.empty()) {
            q.push(str[i]);
            continue;
        }

        if (str[i] == '.' && !q.empty()) {
            q.push(str[i]);
            continue;
        } else {
            break;
        }

        if (c >= 45 && c <= 57) {
            q.push(c);
        } else {
            break;
        }
    }

    if (q.size() == 1) {
        if (q.front() == '+' || q.front() == '-' || q.front() == '.') {
            cout << 0;

            return;
        }
    }

    if (q.empty()) {
        cout << 0;
        return;
    }

    string ans = "";

    while(!q.empty()) {
        ans += q.front();

        q.pop();
    }

    cout << stoll(ans);
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}