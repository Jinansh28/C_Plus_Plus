#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxm = 0, minm = LLONG_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxm) maxm = nums[i];
            if (nums[i] < minm) minm = nums[i];
        }
        return k * (maxm - minm);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 2};
    int k = 4;
    cout << sol.maxTotalValue(nums, k) << endl;
    return 0;
}
