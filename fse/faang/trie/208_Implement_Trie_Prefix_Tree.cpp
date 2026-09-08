#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndWord;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }

            isEndWord = false;
        }
    };
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode *curr = root;

        for (char c: word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEndWord = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        
        for (char c: word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        if (curr->isEndWord) {
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        
        for (char c: prefix) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                return false;
            }

            curr = curr->children[index];
        }

        return true;
    }
};

void solve() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // return True
    cout << trie->search("app") << endl;     // return False
    cout << trie->startsWith("app") << endl; // return True
    trie->insert("app");
    cout << trie->search("app") << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}