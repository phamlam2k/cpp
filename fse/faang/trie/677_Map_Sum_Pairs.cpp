#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class MapSum {
private:
    struct TrieNode
    {
        TrieNode* children[26];
        int value;

        TrieNode () {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }

            value = 0;
        }
    };
    
public:
    TrieNode* root;

    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;

        for (char c: key) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->value = val;
    }

    void backtracking(int &result, TrieNode* node) {
        if (node == nullptr) {
            return;
        }

        if (node->value > 0) {
            result += node->value;
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                backtracking(result, node->children[i]);
            }
        }
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        int result = 0;

        for (char c: prefix) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        backtracking(result, curr);

        return result;
    }
};


void solve() {
    MapSum* mapSum = new MapSum();
    mapSum->insert("apple", 3);  
    cout << mapSum->sum("ap") << endl; 
    mapSum->insert("app", 2);    
    cout << mapSum->sum("ap") << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}