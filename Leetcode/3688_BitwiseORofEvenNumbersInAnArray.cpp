#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) {
            if (i % 2 == 0) ans |= i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    cout << sol.evenNumberBitwiseORs(nums) << endl;
    return 0;
}
