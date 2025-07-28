#include<iostream>
#include<vector>
using namespace std;

//Brute Force
// int countInversions(vector<int> nums){
//     int inv=0;
//     for(int i=0;i<nums.size();i++){
//         for(int j=i+1;j<nums.size();j++){
//             if(nums[i]>nums[j]){
//                 inv++;
//             }
//         }
//     }
//     return inv;
// }



void count(vector<int> &nums,int st,int end,int mid,int &c){
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(nums[i]>nums[j]){
            c+=mid-i+1;
            temp.push_back(nums[j++]);
        }
        else {
            temp.push_back(nums[i++]);
        }
    }
    while(i<=mid) temp.push_back(nums[i++]);
    while(j<=end) temp.push_back(nums[j++]);
    for(int d=0;d<temp.size();d++){
        nums[d+st]=temp[d];
    }
}

void countInversions(vector<int> &nums,int st,int end,int &c){
    if(st<end){
        int mid=st+(end-st)/2;
        countInversions(nums,st,mid,c);
        countInversions(nums,mid+1,end,c);
        count(nums,st,end,mid,c);
    }
}

int main(){
    vector<int> nums={6,3,5,2,7};
    int c=0;
    countInversions(nums,0,4,c);
    cout<<c;
}