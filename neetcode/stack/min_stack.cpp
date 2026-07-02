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

class MinStack {
public:
    stack<int> minStack;
    stack<int> min;

    MinStack() {
        minStack = stack<int>();
        min = stack<int>();
    }
    
    void push(int val) {
        minStack.push(val);
        if (min.empty() || val <= min.top()) {
            min.push(val);
        }
    }
    
    void pop() {
        if (!minStack.empty()) {
            if (minStack.top() == min.top()) {
                min.pop();
            }
            minStack.pop();
        }
    }
    
    int top() {
        return minStack.top();
    }
    
    int getMin() {
        return min.top();
    }
};

signed main() {
    CODEGOD;
}