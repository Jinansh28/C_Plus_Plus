#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int a=nums.size();
    int piv=-1;
    for(int i=a-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            piv=i;
            break;
        }
    }
    if(piv==-1){
        reverse(nums.begin(),nums.end());
        return;
    }
    for(int i=a-1;i>=0;i--){
        if(nums[i]>nums[piv]){
            swap(nums[i],nums[piv]);
            break;
        }
    }
    reverse(nums.begin()+piv+1,nums.end());
   
}

int main() {
    vector<int> nums={3,2,1};
    nextPermutation(nums);
    for(int b=0;b<nums.size();b++){
        cout<<nums[b]<<" ";
    }
    return 0;
}