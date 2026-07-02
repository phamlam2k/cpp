#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string s;
    
    cin >> s;
    
    unordered_map<char, char> mp;

    mp.insert({ ']', '[' });
    mp.insert({ ')', '(' });
    mp.insert({ '}', '{' });

    stack<char> st;
    
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (st.empty()) {
            st.push(s[i]);

            continue;
        }

        int t = st.top();

        if (t == mp[s[i]]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    if (st.empty()) {
        cout << true;
    } else {
        cout << false;
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