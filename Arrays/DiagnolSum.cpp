#include<iostream>
using namespace std;

int sum(int arr[3][3],int n){
    int p=0,s=0;
    for(int i=0;i<n;i++){
        p+=arr[i][i];
        s+=arr[i][n-1-i];
    }
    if(n%2==1){
        return p+s-arr[n/2][n/2];
    }
    return p+s;
}

int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    cout<<sum(arr,3);
}