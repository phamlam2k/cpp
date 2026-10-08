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

    void heapify(vector<int> arr) {
    }

    void heapup(int index) {
        while (index) {
            int parentIndex;
            if (index % 2 == 0) {
                parentIndex = (index - 2) / 2;
            } else {
                parentIndex = (index - 1) / 2;
            }

            if (heapArr[index] < heapArr[parentIndex]) swap(heapArr[index], heapArr[parentIndex]);

            index = parentIndex;
        }
    }

    void heapdown(int index, vector<int> &arr) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < arr.size()) {
            if (arr[left] < arr[index]) swap(arr[left], arr[index]);

            heapdown(left, arr);
        }

        if (right < arr.size()) {
            if (arr[right] < arr[index]) swap(arr[right], arr[index]);
            
            heapdown(right, arr);
        }
    }
public:
    MinHeap(vector<int> arr) {
        heapArr = arr;
        heapdown(0, heapArr);
    }

    void push(int value) {
        heapArr.push_back(value);

        heapup(heapArr.size() - 1);
    }

    int get(int index) {
        return heapArr[index];
    }
};

void solve() {
    MinHeap mH = MinHeap({ 15, 20, 8, 10, 12, 5, 14 });

    cout << mH.get(5) << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}