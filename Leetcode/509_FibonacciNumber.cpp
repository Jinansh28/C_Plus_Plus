#include<iostream>
using namespace std;


//Recursion
// int fib(int n) {
//     if(n==1 || n==0) return n;
//     return fib(n-1)+fib(n-2);
// }

int fib(int n){
    if(n==0 || n==1) return n;
    int a=0,b=1;
    for(int i=2;i<=n;i++){
        if(i%2==0) a=a+b;
        else b=a+b; 
    }
    if(n%2==0) return a;
    else return b;
}

int main(){
    cout<<fib(10);
}