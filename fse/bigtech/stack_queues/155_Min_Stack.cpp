#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <stack>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

stack<int> init;
stack<int> minStack;

void push(int value) {
    init.push(value);

    if (minStack.empty() || value < minStack.top()) {
        minStack.push(value);
    } 
}

void pop() {
    int t = init.top();
    init.pop();

    if (t == minStack.top()) {
        minStack.pop();
    }
}

int top() {
    return init.top();
}

int getMin() {
    return minStack.top();
}

void solve() {
    push(-2);
    push(0);
    push(-3);
    cout << getMin() << endl; // return -3
    pop();
    cout << top() << endl;    // return 0
    cout << getMin() << endl; // return -2
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}