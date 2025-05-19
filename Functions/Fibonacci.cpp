#include<iostream>
using namespace std;

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    int f=fibonacci(n-1)+fibonacci(n-2);
    return f;
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}