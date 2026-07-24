#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

#define endl "\n"
#define int long long
#define CODEGOD ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class NumArray {
public:
    vector<int> pre_sums;

    NumArray(vector<int>& nums) {
        int len = nums.size();

        pre_sums.push_back(nums[0]);

        for (int i = 1; i < len; i++) {
            pre_sums.push_back(nums[i] + pre_sums[i - 1]);  
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return pre_sums[right];
        }

        return pre_sums[right] - pre_sums[left - 1];
    } 
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */