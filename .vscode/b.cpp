//arr intersection 
//unique elements
#include <iostream>
#include <cmath>
using namespace std;

#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int write_index = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[write_index - 1]) {
            arr[write_index] = arr[i];
            ++write_index;
        }
    }

    return write_index;
}

int partition(int arr[],int start, int end){

    int i = start , j = i + 1;
    int pivot = arr [start];


    while (start < end && j<=end){
        if (arr[j] < pivot) {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        j++;
    }

    int temp = arr[start];
    arr[start] = arr[i];
    arr[i] = temp;

    return i;
}

int quicksort(int arr[] , int start , int end ){


    if (start < end){

        int pivot = partition(arr,start,end);
        quicksort(arr , start , pivot - 1);
        quicksort(arr , pivot + 1 , end );

    }

    return 0;
}

int main(){

    int arr1[] = {4,2,7,8,1,2,5,4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    int arr2[] = {1,2,3,4,2,5,3,4,4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    quicksort(arr1,0,n1-1); // 1 2 2 4 4 5 7 8    1 2 4 5 7 8
    quicksort(arr2,0,n2-1); // 1 2 2 3 3 4 4 4 5  1 2 3 4 5

    n1 = removeDuplicates(arr1, n1);
    n2 = removeDuplicates(arr2, n2);

    int inc = 0;
    for(int i = 0 ; i < n1 && i+inc <= max(n1,n2) ; i++){
        if (arr1[i] == arr2[i+inc]) cout<<arr1[i]<<" ";
        else if (arr1[i] > arr2[i+inc]) {inc++ ; i--;} 
        else continue;        
    }

}