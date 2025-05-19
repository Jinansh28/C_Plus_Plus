#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=2*n;
    int b=a*a;
    for(int i=1;i<=b;i++){
        int j=i%a;
        int k=(i/a)+1;
        if(j==0){
            j=a;
            k--;
        }
        int l=j+k;
        int o=j-k;
        if(k<=n){
            if(j<=k || l>a){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        else{
            if(l<a+2 || j>=k){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        if(j==a){
            cout<<endl;
        }
    }
    return 0;
}