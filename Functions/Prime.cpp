#include<iostream>
using namespace std;

int prime(int n){
    int a;
    for(int i=2;i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int a=prime(n);
    if(a==0){
        cout<<"Not a prime";
    }
    else{
        cout<<"Prime";
    }
    return 0;
}