#include<iostream>
using namespace std;

int main(){
    int a[]={5,15,22,1,-15,24};
    int size=sizeof(a)/sizeof(a[0]);
    int min=a[0],max=a[0],p,q;
    for(int i=0;i<size;i++){
        if(min<a[i]){
            min=a[i];
            p=i;
        }
        if(max>a[i]){
            max=a[i];
            q=i;
        }
    }
    int temp=a[p];
    a[p]=a[q];
    a[q]=temp;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}