#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=2*n-1;
    int b=a*a;
    for(int i=1;i<=b;i++){
        int j=i%a;
        int k=(i/a)+1;
        if(j==0){
            j=a;
            k--;
        }
        int l=j+k;
        int m=j-k;
        int o=k-j;
        if(l==n+1 || l==3*n-1){
            cout<<"*";
        }
        else if(m==n-1 || o==n-1){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
        if(j==a){
            cout<<endl;
        }
    }
    return 0;
}