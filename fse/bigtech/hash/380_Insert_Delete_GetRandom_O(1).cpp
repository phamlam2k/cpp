#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int indexToRemove = mp[val];
        int lastElement = nums.back();

        nums[indexToRemove] = lastElement;
        mp[lastElement] = indexToRemove;

        nums.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

void solve() {
    RandomizedSet *randomizedSet = new RandomizedSet();
    randomizedSet->insert(1); // Inserts 1 to the set-> Returns true as 1 was inserted successfully->
    randomizedSet->remove(2); // Returns false as 2 does not exist in the set->
    randomizedSet->insert(2); // Inserts 2 to the set, returns true-> Set now contains [1,2]->
    cout << randomizedSet->getRandom() <<endl; // getRandom() should return either 1 or 2 randomly->
    randomizedSet->remove(1); // Removes 1 from the set, returns true-> Set now contains [2]->
    randomizedSet->insert(2); // 2 was already in the set, so return false->
    cout << randomizedSet->getRandom() << endl;
}

signed main() {
    CODEGOD;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}