#include<iostream>
#include<cmath>
using namespace std;

int count(int n){
    int i=0;
    while(n!=0){
        i++;
        n=n/2;
    }
    return i;
}

int complement2s(int n,int count){
    int a=pow(2,count)-1;
    n=a-n;
    int i=0,complement=0;
    while(n!=0){
        int b=n%2;
        float c=pow(10,i);
        b=b*c;
        n=n/2;
        i++;
        complement+=b;
    }
    return complement;
}
int main(){
    int n;
    cin>>n;
    int a=count(n);
    cout<<complement2s(n,a);
    return 0;
}