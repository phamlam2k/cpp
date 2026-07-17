#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void init(map<char, int> &mp) {
    mp.insert({
        '*', 2
    });
    mp.insert({
        '/', 2
    });
    mp.insert({
        '+', 1
    });
    mp.insert({
        '-', 1
    });
}

void solve() {
    string str;

    cin >> str;

    int len = str.length();

    map<char, int> mp;

    init(mp);

    vector<char> ans;
    stack<char> st;

    for (int i = 0; i < len; i++) {
        int num = str[i] - 0;

        if (num >= 65 && num <= 90) {
            ans.push_back(str[i]);
        } else {
            if (str[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }

                if (!st.empty() && st.top() == '(') {
					st.pop();
				}
            } else if (str[i] == '(') {
                st.push(str[i]);
            } else {
                while (!st.empty() && mp[str[i]] <= mp[st.top()]) {
                    ans.push_back(st.top());
                    st.pop();
                }

                st.push(str[i]);
            }
        }
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    int s = ans.size();

    for (int i = 0; i < s; i++) {
        cout << ans[i];
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