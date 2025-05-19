#include<iostream>
using namespace std;

int main(){
    int a[]={5,15,22,1,-15,24};
    int size=sizeof(a)/sizeof(a[0]);
    int min=a[0],max=a[0];
    for(int i=0;i<size;i++){
        if(min<a[i]){
            min=a[i];
        }
        if(max>a[i]){
            max=a[i];
        }
    }
    cout<<min<<endl;
    cout<<max;
    return 0;
}