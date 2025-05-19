#include<iostream>
using namespace std;
void usingloop(int n){
    while(n!=1){
        if(n%2==1){
            cout<<"Number is not a power of 2";
            return ;
        }
        n=n/2;
    }
    cout<<"Number is a power of 2";
}
void usingbitwise(int n){
    if(((n & (n-1))==0)){
        cout<<"Number is a power of 2";
    }
    else{
        cout<<"Number is not a power of 2";
    }
}
int main(){
    int n;
    cin>>n;
    usingloop(n);
    cout<<endl;
    usingbitwise(n);
}