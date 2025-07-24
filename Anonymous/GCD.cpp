#include<iostream>
using namespace std;


//O(m) m<n
// int GCD(int a,int b){
//     if(a==0) return b;
//     if(b==0) return a;
//     if(a==b) return a;
//     int ans=1;
//     for(int i=1;i<=min(a,b);i++){
//         if(a%i==0 && b%i==0){
//             ans=i;
//         }
//     }
//     return ans;
// }

//Euclid's Algorithm
int GCD(int a,int b){
    while(a!=0 || b!=0){
        if(a==0) return b;
        if(b==0) return a;
        if(a==b) return a;
        if(a>b){
            a=a%b;
        }
        else{
            b=b%a;
        }
    }
    return -1;
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int a=28,b=20;
    cout<<gcd(a,b);
}