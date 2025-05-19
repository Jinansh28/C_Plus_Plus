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

void primeN(int n){
    for(int i=1;i<=n;i++){
        int a=prime(i);
        if(a==1){
            cout<<i<<endl;
        }
    }
}
int main(){
    int n;
    cin>>n;
    primeN(n);
    return 0;
}