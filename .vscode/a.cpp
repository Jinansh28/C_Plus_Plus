#include<iostream>
#include<math.h>

using namespace std;
int main(){
    // int n;
    // float b=0,a,i=0;
    // cin>>n;
    // while(n>0){
    //     a=n%2;
    //     n=n/2;
    //     b=b+(a*pow(10,i));
    //     i++;
    // }
    // cout<<b;
    // return 0;
    // int n;
    // float b=0,i=0,a;
    // cin>>n;
    // while(n>0){
    //     a=n%10;
    //     b=a*pow(2,i)+b;
    //     n=n/10;
    //     i++;
    // }
    // int a,b;
    // a=4;
    // b=8;
    // cout<< (40>>2);
    int a[]={5,15,22,1,-15,24};
    int b=0,c=0;
    int min=a[0],max=min;
    int size=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<size;i++){
        if(a[i]<min){
            min=a[i];
            b=i;
        }
        if(a[i]>max){
            max=a[i];
            c=i;
        }
    }
    for(int i=0,j=size-1;i<j;i++,j--){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<min<<" "<<b<<endl;
    cout<<max<<" "<<c<<endl;
    return 0;
}