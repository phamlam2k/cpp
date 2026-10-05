#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve() {
    string s;

    cin >> s;

    int len = s.size();

    if (len <= 10) {
        cout << 0;
        return;
    }

    unordered_map<char, int> charMap = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    unordered_set<int> checker;
    
    int K = 4;
    int maxnum = 1;
    for (int i = 1; i < 10; i++) {
        maxnum *= K;
    }

    long long sum = 0;

    for (int i = 0; i < 10; i++) {
        sum = ((K * sum) + charMap[s[i]]);
    }

    checker.insert(sum);
    
    unordered_set<string> result;

    for (int i = 0; i < len - 10; i++) {
        int num = charMap[s[i]];
        int nextNum = charMap[s[i + 10]];

        sum = K * (sum - num * maxnum) + nextNum;
        
        if (checker.find(sum) != checker.end()) {
            result.insert(s.substr(i + 1, 10));
        } else
        {
            checker.insert(sum);
        }
    }

    vector<string> ans;

    for (string str: result) {
        cout << str << endl;
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