#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=n*n;
    char b='A';
    for(int i=1;i<=a;i++){
        int j=i%n;
        if(j==0){
            j=n;
        }
        cout<<b++;
        if(j==n){
            cout<<endl;
        }
    }
    return 0;
}