// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int isvalid(vector <int> &arr,int mid,int k){
    int j=1,sum=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>mid) return 0;
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else if(sum+arr[i]>mid){
            j++;
            sum=arr[i];
        }
    }
    if(j<=k) return 1;
    else return 0;
}

int findPages(vector<int> &arr, int k) {
    if(k>arr.size()) return -1;
    int st=0,end=0;
    for(int i=0;i<arr.size();i++){
        end+=arr[i];
    }
    int minpages=end;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(arr,mid,k)){
            end=mid-1;
            minpages=min(minpages,mid);
        }
        else{
            st=mid+1;
        }
    }
    return minpages;
}

int main() {
    vector<int> arr={12, 34, 67, 90};
    int k = 2;
    cout<<findPages(arr,k);
}