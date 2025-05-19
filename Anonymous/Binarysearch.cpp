#include<iostream>
using namespace std;

//O(log n)
int binarySearch(int a[],int target,int end){
    int start=0;
    int mid=start+(end-start)/2;
    while(start<=end){
        mid=(start+end)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

int binarysearch(int a[],int start,int end,int target){
    int mid=start+(end-start)/2;
    if(start<=end){
    if(a[mid]==target)
        return mid;

    else if(a[mid]>target)
        return binarysearch(a,start,mid-1,target);

    else
        return binarysearch(a,mid+1,end,target);
    }
    else
    return -1;
}
int main(){
    int a[]={-1,0,3,4,5,9,12};
    int target=10;
    int end=(sizeof(a)/sizeof(a[0])-1);
    cout<<binarysearch(a,0,end,target);
}