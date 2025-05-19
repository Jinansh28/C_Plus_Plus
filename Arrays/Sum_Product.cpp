#include<iostream>
using namespace std;

int sum(int a[],int size){
    int n=0;
    for(int i=0;i<size;i++){
        n=n+a[i];
    }
    return n;
}

int product(int a[],int size){
    int n=1;
    for(int i=0;i<size;i++){
        n=n*a[i];
    }
    return n;
}

int main(){
    int a[]={4,2,7,8,1,2,5};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<"The sum of elements of the array is "<<sum(a,size)<<endl;
    cout<<"The product of elements of the array is "<<product(a,size);
    return 0;
}