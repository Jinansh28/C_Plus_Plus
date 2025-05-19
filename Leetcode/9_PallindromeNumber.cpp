#include<iostream>
#include<cmath>
using namespace std;

int count(int x){
    int count=0;
    while(x>0){
        x=x/10;
        count++;
    }
    return count;
}
// bool isPalindrome(int x){
//     if(x<0) return false;
//     int n=count(x);
//     if(n==1) return true;
//     int a=0;
//     for(int i=0;i<n/2;i++){
//         int c=n-a-1;
//         float b=pow(10,c);
//         a+=2;
//         c=(float)b;
//         if(x/c!=x%10){
//             return false;
//         }
//         x=x/10;
//         c=c/10;
//         x=x%c;
//     }
//     return true;
// }

bool isPalindrome(int x){
    int a=x,b=0;
    while(a>0){
        b*=10;
        int c=a%10;
        b+=c;
        a=a/10;
    }
    return x==b;
}

int main(){
    int x=11;
    cout<<isPalindrome(x);
}