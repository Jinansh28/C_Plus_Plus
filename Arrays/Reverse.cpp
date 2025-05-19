#include<iostream>
using namespace std;

int main(){
    int a[]={4,2,7,8,1,2,5};
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0,j=size-1;i<j;i++,j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}