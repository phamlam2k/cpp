#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

queue<int> q;

void push(int x) {
    q.push(x);
        
    int size = q.size();
    
    for (int i = 0; i < size - 1; i++) {
        q.push(q.front());
        q.pop();
    }
}

int pop() {
    int top = q.front();

    q.pop();

    return top;
}

int top() {
    int top = q.front();
    
    return top;
}

bool empty() {
    return q.empty();
}

void solve() {
    push(1);
    push(2);
    cout << top() << endl; // return 2
    cout << pop() << endl;
    cout << empty() << endl; // return False
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}