#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c=2*n-1;
    int a=n*c;
    int b=1;
    for(int i=1;i<=a;i++){
        int j=i%c;
        int k=(i/c)+1;
        int m=j+k;
        int o=j-k;
        if(j==1){
            b=1;
        }
        if(j==0){
            j=c;
            k--;
        }
        if(m<=n || o>=n){
            cout<<" ";
        }
        else{
            cout<<b;
            if(j<n){
                b++;
            }
            else{
                b--;
            }
        }
        if(j==c){
            cout<<endl;
        }
    }
    return 0;
}