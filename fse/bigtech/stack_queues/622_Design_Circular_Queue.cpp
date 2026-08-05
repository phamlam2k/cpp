#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<int> q;
int capacity;
int count;
int head = 0; 
int tail = 0;

bool enQueue(int value) {
    if (count == capacity) return false;

    int tail = (head + count) % capacity;

    q[tail] = value;
    count++;

    return true;
}

bool deQueue() {
    head++;
    count--;
}

int Front() {
    if (isEmpty()) return -1;

    return q[head];
}

int Rear() {
    if (isEmpty()) return -1;

    int tail = (head + count - 1) % capacity;

    return q[tail];
}

bool isEmpty() {
    return count == 0;
}

bool isFull() {
    return count == capacity;
}

void solve() {
    capacity = 3;
    q.resize(3);
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}