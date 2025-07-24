#include<iostream>
#include<vector>
using namespace std;

//O(n) Optimal
// void sortColors(vector <int> &nums){
//     int a=0,b=0,c=0;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]==0){
//             a++;
//         }
//         else if(nums[i]==1){
//             b++;
//         }
//         else{
//             c++;
//         }
//     }
//     b+=a;
//     c+=b;
//     for(int j=0;j<nums.size();j++){
//         if(j<a){
//             nums[j]=0;
//         }
//         else if(j<b){
//             nums[j]=1;
//         }
//         else{
//             nums[j]=2;
//         }
//     }
//     for(int i=0;i<nums.size();i++){
//         cout<<nums[i]<<" ";
//     }
// }


//Optimised
void sortColors(vector<int> &nums){
    int low=0,mid=0,high=nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid++],nums[low++]);
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high--]);
        }
    }
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    vector<int> nums={2,0,1,2,0,1,2,1,0,1,2,0};
    sortColors(nums);
}