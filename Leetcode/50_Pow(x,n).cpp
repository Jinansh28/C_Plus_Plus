#include<iostream>

using namespace std;

float pow(float x,int n){
    float b=1/x,ans=0;
    while(n!=0){
    int a=n%10;
    b=b*x;
    if(a==1){
        ans+=ans;
    }
    n=n/10;
    }
    return ans;
}

int main(){
    cout<<pow(5,101);
}