#include<iostream>
#include<vector>
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
// void quicksort(vector<int>& arr, int left, int right) {
//     if (left >= right) return;

//     int pivot = arr[right];
//     int partitionIndex = left;

//     for (int i = left; i < right; i++) {
//         if (arr[i] <= pivot) {
//             swap(arr[i], arr[partitionIndex]);
//             partitionIndex++;
//         }
//     }
//     swap(arr[partitionIndex], arr[right]);

//     quicksort(arr, left, partitionIndex - 1);
//     quicksort(arr, partitionIndex + 1, right);
// }
// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> a(2,0);
//     vector<int> d=nums;
//     quicksort(nums,0,nums.size()-1);
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