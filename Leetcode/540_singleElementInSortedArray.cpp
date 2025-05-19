#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int st=1,end=nums.size()-2;
    if(nums.size()==1){
        return nums[0];
    }
    if(nums.size()==2){
        return -1;
    }
    if(nums[1]!=nums[0]){
            return nums[0];
    }
    if(nums[nums.size()-1]!=nums[nums.size()-2]){
        return nums[nums.size()-1];
    }
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
            return nums[mid];
        }
        if(nums[mid]==nums[mid-1]){ 
            if(mid%2==1){
                 st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        else if(nums[mid]==nums[mid+1]){
            if(mid%2==1){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums={1,1,2,3,3,4,4};
    cout<<singleNonDuplicate(nums);
}