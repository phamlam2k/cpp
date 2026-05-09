#pragma once // Chống include trùng lặp (rất tốt, bạn đã dùng đúng)
#include <bits/stdc++.h>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class HashSet {
private:
    int hashSize = 10;
    vector<vector<int>> bucket;
public:
    HashSet();

    bool isEmpty();
    int hashFunction(int key);
    void add(int key);
    bool search(int key);
};
