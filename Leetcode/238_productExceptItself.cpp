#include<iostream>
#include<vector>
using namespace std;

//Brute Force
// vector<int> productExceptSelf(vector<int>& nums) {
//     vector<int> ans(nums.size(),0);
//     for(int i=0;i<nums.size();i++){
//         int a=1;
//         for(int j=0;j<nums.size();j++){
//             if(i==j){
//                 continue;
//             }
//             a=a*nums[j];
//         }
//         ans[i]=a;
//     }
//     return ans;   
// }


vector<int> productExceptSelf(vector<int>& nums){
    int lp=1,rp=1;
    vector<int> ans(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        lp=lp*nums[i-1];
        ans[i]=lp;
    }
    for(int j=nums.size()-2;j>=0;j--){
        rp=rp*nums[j+1];
        ans[j]=rp*ans[j];
    }
    return ans;
}

int main(){
    vector<int> nums={1,2,3,4};
    vector<int> a=productExceptSelf(nums);
    for(int i:a){
        cout<<i<<" ";
    }
}