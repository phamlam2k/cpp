#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int index;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }

        index = -1;
    }
};

// i love eating burger

void solve() {
    string sentence, searchWord;

    cin >> sentence;
    cin >>  searchWord;

    int len = sentence.size();

    TrieNode* root = new TrieNode();

    TrieNode* curr = root;

    int num = 1;

    for (int i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            curr = root;
            num += 1;

            continue;
        }

        int index = sentence[i] - 'a';

        if (curr->children[index] == nullptr) {
            curr->children[index] = new TrieNode();
            curr->children[index]->index = num;
        }

        curr = curr->children[index];
    }

    int len_searchword = searchWord.size();

    for (int i = 0; i < len_searchword; i++) {
        int index = searchWord[i] - 'a';

        if (root->children[index] == nullptr) {
            cout << -1;

            return;
        }

        root = root->children[index];
    }

    cout << root->index;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}