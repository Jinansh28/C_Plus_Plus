#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=n*n;
    for(int i=1;i<=a;i++){
        int j=i%n;
        int k=(i/n)+1;
        if(j==0){
            j=n;
            k--;
        }
        if(k<=j){
            cout<<k;
        }
        else{
            cout<<" ";
        }
        if(j==n){
            cout<<endl;
        }
    }
    return 0;
}