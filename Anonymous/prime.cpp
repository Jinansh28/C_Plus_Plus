#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number";
    cin>>n;
    int a,b=sqrt(n);
    for(int i=2;i<=b;i++){
        if(n%i==0){
            cout<<"Not a prime";
            break;
        }
        a=i;
    }
    if(a==b || n==2){
        cout<<"Prime";
    }
    return 0;
}