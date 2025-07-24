#include<iostream>
#include<vector>
using namespace std;

void permutations(vector<int> &nums,vector<vector<int>> &ans,int i){
    if(i==nums.size()){
        ans.push_back({nums});
        return;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        permutations(nums,ans,i+1);
        swap(nums[i],nums[j]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int i=0;
    permutations(nums,ans,i);
    return ans;
}

int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> a=permute(nums);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}