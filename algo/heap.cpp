#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class MinHeap {
private:
    vector<int> heapArr;

    void heapify() {
        int size = heapArr.size();
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapdown(i);
        }
    }

    void heapup(int index) {
        while (index) {
            int parentIndex;
            if (index % 2 == 0) {
                parentIndex = (index - 2) / 2;
            } else {
                parentIndex = (index - 1) / 2;
            }

            if (heapArr[index] < heapArr[parentIndex]) {
                swap(heapArr[index], heapArr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapdown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heapArr.size() && heapArr[left] < heapArr[smallest]) {
            smallest = left;
        }

        if (right < heapArr.size() && heapArr[right] < heapArr[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            swap(heapArr[index], heapArr[smallest]);
            heapdown(smallest);
        }
    }
public:
    MinHeap(vector<int> arr) {
        heapArr = arr;
        heapify();
    }

    void push(int value) {
        heapArr.push_back(value);

        heapup(heapArr.size() - 1);
    }

    void pop() {
        if (heapArr.empty()) return;

        heapArr[0] = heapArr.back();

        heapArr.pop_back();
        heapdown(0);
    }

    void del (int index) {
        if (heapArr.empty()) return;

        if (index == heapArr.size() - 1) {
            heapArr.pop_back();

            return;
        } 

        heapArr[index] = heapArr.back();
        heapArr.pop_back();
        heapup(index);
        heapdown(index);
    }

    int get(int index) {
        return heapArr[index];
    }
};

void solve() {
    MinHeap mH = MinHeap({ 15, 20, 8, 10, 12, 5, 14 });

    cout << mH.get(1) << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}