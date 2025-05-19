#include<iostream>
using namespace std;

int main(){
    int a[]={4,2,7,8,1,2,4};
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++){
        bool flag=true;
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
                flag=false;
            }
        }
        if(flag==true){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}