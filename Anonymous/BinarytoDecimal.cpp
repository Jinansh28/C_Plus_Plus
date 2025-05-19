#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,decimal=0,i=0;
    cin>>n;
    while(n!=0){
        int a=n%10;
        float b=pow(2,i);
        a=a*b;
        decimal+=a;
        i++;
        n=n/10;
    }
    cout<<decimal;
    return 0;
}
