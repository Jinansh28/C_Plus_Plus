#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> subset(vector<int> &nums,vector<int> ans,vector<vector<int>>& subs,int i){
    if(i>=nums.size()){
        subs.push_back({ans});
        return subs;
    }
    ans.push_back(nums[i]);
    subset(nums,ans,subs,i+1);
    ans.pop_back();
    subset(nums,ans,subs,i+1);
    return subs;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> ans;
        int i=0;
        subset(nums,ans,subs,i);
        return subs;
}

int main(){
    vector<int> nums={1,2,2};
    vector<vector<int>> a=subsets(nums);
    for (int i = 0; i < a.size(); i++) {
        cout << "[";
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << "]\n";
    }
}