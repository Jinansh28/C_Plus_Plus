#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int LCM(int a,int b){
    int GCD=gcd(a,b);
    return (a*b)/GCD;
}

int main(){
    int a=20,b=28;
    cout<<LCM(a,b);
}