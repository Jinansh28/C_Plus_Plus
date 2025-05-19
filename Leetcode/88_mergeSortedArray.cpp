#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int> nums1,vector<int> nums2,int m,int n){
    int a=0;

    for(int i=m;i<m+n;i++){
        nums1[i]=nums2[a];
        a++;
    }

    for(int i:nums1){
        cout<<i<<" ";
    }
    return quickSort(nums1,0,m+n-1);
}

int main(){
    vector<int> nums1={0};
    vector<int> nums2={1};
    int m=0,n=1;
    merge(nums1,nums2,m,n);
}