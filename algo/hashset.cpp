#include "HashSet.h"

HashSet::HashSet() {
    bucket.resize(hashSize);
}

bool HashSet::isEmpty() {
    if (bucket.size() == 0) {
        return true;
    }

    return false;
}

int HashSet::hashFunction (int key) {
    return key % hashSize;
}

void HashSet::add(int key) {
    int hashValue = hashFunction(key);

    for (int idx: bucket[hashValue]) {
        if (idx == key) {
            return;
        }
    }

    bucket[hashValue].push_back(key);
}

bool HashSet::search(int key) {
    int hashValue = hashFunction(key);

    for (int idx: bucket[hashValue]) {
        if (idx == key) {
            return true;
        }
    }

    return false;
}

signed main() {
    int n;

    cin >> n;

    vector<int> arr(n + 1);
    HashSet hs;

    for (int i = 0; i <= n;i++ ) {
        arr[i] = i;
        hs.add(i);
    }

    cout << hs.search(101) << endl;
    cout << hs.search(200) << endl;
    cout << hs.search(50) << endl;
    cout << hs.search(20) << endl;
}