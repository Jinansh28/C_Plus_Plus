#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

double myPow(double x,int y){

    double ans=1;

    if(y<0){
        x=1/x;
        y*=-1;
    }

    while(y!=0){
        int a=y%2;
        if(a==1){
            ans*=x;
        }
        x=x*x;
        y=y/2;
    }

    return ans;

}

int main(){

    cout<<myPow(2,-20);
}