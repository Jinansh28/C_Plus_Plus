#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>& nums,int target,int st,int end){  
    if(st>end) return -1;
    int mid=st+(end-st)/2;        
    if(nums[mid]==target) return mid;
    else if(nums[mid]>target) return binarysearch(nums,target,st,mid-1);
    else return binarysearch(nums,target,mid+1,end);
}

int search(vector<int>& nums, int target) {
    int st=0,end=nums.size()-1;
    return binarysearch(nums,target,st,end);
}

int main(){
    vector<int> nums={1,2,3,4,5};
    int target=9;
    cout<<search(nums,target);
}