#include <bits/stdc++.h>
using namespace std;

int smallestAbsent(vector<int>& nums) {
    unordered_set<int> m;
    int avg = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        avg += nums[i];
        m.insert(nums[i]);
    }
    avg = avg / n;
    if (avg < 0) avg = 1;
    else avg++;
    
    while (m.find(avg) != m.end()) {
        avg++;
    }
    return avg;
}

int main() {
    vector<int> nums = {1, 2, 3, 5, 6};
    
    int result = smallestAbsent(nums);
    cout << result;
    
    return 0;
}
