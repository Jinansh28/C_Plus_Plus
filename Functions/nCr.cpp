#include<iostream>
using namespace std;

int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    int f=n*factorial(n-1);
    return f;
}

int nCr(int n,int r){
    return factorial(n)/(factorial(n-r)*factorial(r));
}

int main(){
    int n,r;
    cin>>n;
    cin>>r;
    cout<<nCr(n,r);
    return 0;
}