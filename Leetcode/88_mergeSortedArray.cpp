#include<iostream>
#include<vector>
using namespace std;

//NlogN
// int partition(vector<int>& arr, int low, int high) {

//     int pivot = arr[high];

//     int i = low - 1;

//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[i + 1], arr[high]);  
//     return i + 1;
// }

// void quickSort(vector<int>& arr, int low, int high) {
  
//     if (low < high) {

//         int pi = partition(arr, low, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// void merge(vector<int> nums1,vector<int> nums2,int m,int n){
//     int a=0;

//     for(int i=m;i<m+n;i++){
//         nums1[i]=nums2[a];
//         a++;
//     }

//     for(int i:nums1){
//         cout<<i<<" ";
//     }
//     return quickSort(nums1,0,m+n-1);
// }


//Optimised O(m+n)
void merge(vector<int> &nums1,int m,vector<int> &nums2,int n){
    for(int i=m+n-1;i>=0;i--){
        if(m==0){
            nums1[i]=nums2[n-1];
            n--;
        }
        else if(n==0){
            nums1[i]=nums1[m-1];
            m--;
        }
        else if(nums1[m-1]>nums2[n-1]){
            nums1[i]=nums1[m-1];
            m--;
        }
        else{
            nums1[i]=nums2[n-1];
            n--;
        }
    }
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
}


int main(){
    vector<int> nums1={2,4,6,0,0,0};
    vector<int> nums2={1,3,5};
    int m=3,n=3;
    merge(nums1,m,nums2,n);
}