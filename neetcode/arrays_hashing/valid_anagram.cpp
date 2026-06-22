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

    int len1 = str1.length();
    int len2 = str2.length();

    if (len1 != len2) {
        cout << false;

        return;
    }

    string key1 = string(26, '0');
    string key2 = string(26, '0');


    for (int i = 0; i < len1; i++) {
        int idx1 = str1[i] - 'a';
        int idx2 = str2[i] - 'a';

        
        key1[idx1]++;
        key2[idx2]++;
    }

    bool check = key1 == key2;

    cout << check;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}