#include<iostream>
using namespace std;

int sumOfDigtis(int n){
    int s=0;
    while(n!=0){
        int a=n%10;
        s+=a;
        n=n/10;
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    cout<<sumOfDigtis(n);
    return 0;
}