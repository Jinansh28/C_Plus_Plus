#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//O(n^2)
// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> a(2,0);
//     for(int i=0;i<nums.size();i++){
//         for(int j=i+1;j<nums.size();j++){
//             if(nums[i]+nums[j]==target){
//                 a[0]=i,a[1]=j;
//             }
//         }
//     }
//     return a;
// }


//O(nlogn)
// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> a(2,0);
//     vector<int> d=nums;
//     sort(nums.begin(),nums.end());
//     int i=0,j=nums.size()-1;
//     while(1){
//         int b=nums[i]+nums[j];
//         if(b==target){
//             a[0]=nums[i],a[1]=nums[j];
//             break;
//         }
//         else if(b>target){
//             j--;
//         }
//         else{
//             i++;
//         }
//     }
//     int e=0;
//     for(int m=0;m<d.size(),e<2;m++){
//         if(a[0]==d[m]){
//             a[0]=m;
//             e++;
//         }
//         else if(a[1]==d[m]){
//             a[1]=m;
//             e++;
//         }
//     }
//     return a;     
// }

//O(n)
vector<int> twoSum(vector<int> &nums,int target){
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        int first=nums[i];
        int second=target-first;
        if(m.find(second)!=m.end()){
            ans.emplace_back(m[second]);
            ans.emplace_back(i);
            return ans;
        }
        m.emplace(first,i);
    }
}

int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> p=twoSum(nums,target);
    for(auto i: p){
        cout<<i<<" ";
    }
}