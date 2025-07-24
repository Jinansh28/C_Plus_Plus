#include<iostream>
using namespace std;

int maxrowsum(int arr[][4],int r,int c){
    int maxsum=0;
    for(int i=0;i<r;i++){
        int sum=0;
        for(int j=0;j<c;j++){
            sum+=arr[i][j];
        }
        maxsum=max(maxsum,sum);
    }
    return maxsum;
}

int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout<<maxrowsum(arr,3,4);
}