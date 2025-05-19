#include<iostream>
#include<vector>
using namespace std;

//Brute Force O(n^2)
// void pairSum(vector<int> nums,int target){

//     for(int i=0;i<nums.size();i++){

//         for(int j=i+1;j<nums.size();j++){

//             if(target==nums[i]+nums[j]){
//                 cout<<nums[i]<<" "<<nums[j];
//             }

//         }
//     }
// }


//Optimised O(n)
void pairSum(vector<int> nums,int target){

    for(int i=0,j=nums.size()-1;i<nums.size();){

        int ps=nums[i]+nums[j];

        if(ps==target){
            cout<<nums[i]<<" "<<nums[j];
            break;
        }
        else if(ps<target){
            i++;
        }
        else{
            j--;
        }
    }
}


int main(){

    vector <int> nums={1,2,7,9,10};
    int target=8;

    pairSum(nums,target);
    return 0;
}
