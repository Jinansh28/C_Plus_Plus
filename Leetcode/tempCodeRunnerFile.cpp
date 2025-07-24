#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    unordered_map<int,int> m;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        m.emplace(nums[i],i);
    }