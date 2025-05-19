#include<iostream>
#include<vector>
using namespace std;

//O(n^2)

// int majorityElement(vector <int> nums){
//     for(int i=0;i<=nums.size()/2;i++){
//         int a=1;
//         for(int j=i+1;j<nums.size();j++){
//             if(nums[i]==nums[j]){
//                 a++;
//             }
//         }
//         if(a>nums.size()/2){
//             return nums[i];
//         }
//     }
//     if(nums.size()==1){
//         return nums[0];
//     }
//     return -1;
// }

//O(n)

int majorityElement(vector<int> nums){
    int freq=0,ans=0;
    for(int i=0;i<nums.size();i++){
        if(freq==0){
            ans=nums[i];
        }
        if(nums[i]==ans){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}
int main(){
    vector <int> nums={6,5,5};
    cout<<majorityElement(nums);
}