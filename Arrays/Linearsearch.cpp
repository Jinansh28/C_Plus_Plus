#include<iostream>
using namespace std;

int main(){
    int a[]={4,2,7,8,1,2,5};
    int target =8;
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++){
        if(a[i]==target){
            cout<<i;
            break;
        }
    }
    return 0;
}