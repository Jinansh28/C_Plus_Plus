#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// O(n^2)

// int MaxSubSum(vector <int> nums){
//     int maxsum=INT_MIN;
//     for(int i=0;i<nums.size();i++){
//         int sum=0;
//         for(int j=i;j<nums.size();j++){
//             sum+=nums[j];
//             if(sum>maxsum){
//                 maxsum=sum;
//             }
//         }
//     }
//     return maxsum;
// }


//O(n): Kadane's Algorithm

int MaxSubSum(vector <int> nums){
    int maxsum=-1e9,current=0;
    for(int i=0;i<nums.size();i++){
        current+=nums[i];
        if(current>maxsum){
            maxsum=current;
        }
        if(current<0){
            current=0;
        }
    }
    return maxsum;
}

int main(){
    vector <int> nums={3,-4,5,4,-1,7,-8};
    cout<<MaxSubSum(nums);
    return 0;
}