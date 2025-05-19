#include<iostream>
#include<vector>
using namespace std;
// int singleNumber(vector<int> nums){
//     for (int i=0;i<=nums.size()-1;i++){
//         int a=0;
//         for(int j=0;j<=nums.size()-1;j++){
//             if(j==i){
//                 continue;
//             }
//             if(nums[i]==nums[j]){
//                 continue;
//             }
//             else{
//                 a++;
//             }
//         }
//         if(a==nums.size()-1){
//             return nums.at(i);
//         }
//     }
//     return -1;
// }

int singleNumber(vector <int> nums){
    int a=0;
    for(int i:nums){
        a=a^i;
    }
    return a;
}

int main(){
    vector <int> nums={2,2,1};
    cout<<singleNumber(nums);
}