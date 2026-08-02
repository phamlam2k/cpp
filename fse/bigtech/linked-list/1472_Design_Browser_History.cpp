#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct ListNode
{
    string val;
    ListNode* next;
    ListNode* prev;

    ListNode(): val(""), next(nullptr), prev(nullptr) {}
    ListNode(string v): val(v), next(nullptr), prev(nullptr) {}
    ListNode(string v, ListNode* n, ListNode* p): val(v), next(n), prev(p) {}
};

ListNode* visitNode;

void BrowserHistory (string homepage) {
    visitNode = new ListNode(homepage);
}

void visit(string url) {
    ListNode* newNode = new ListNode(url);

    ListNode* curr = visitNode->next;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    visitNode->next = newNode;
    newNode->prev = visitNode;
        
    visitNode = newNode;
}

string back(int steps) {
    while (steps > 0 && visitNode->prev != nullptr) {
        visitNode = visitNode->prev;
        steps--;
    }
    return visitNode->val;
}

string forward(int steps) {
    while (steps > 0 && visitNode->next != nullptr) {
        visitNode = visitNode->next;
        steps--;
    }
    return visitNode->val;
}

void solve() {
    BrowserHistory("leetcode.com");

    visit("google.com");
    visit("facebook.com"); 
    visit("youtube.com"); 

    string res1 = back(1);
    cout << res1 << endl;

    string res2 = back(1);
    cout << res2 << endl;

    string res3 = forward(1);
    cout << res3 << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}