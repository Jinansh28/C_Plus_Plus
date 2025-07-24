#include<iostream>
#include<vector>
using namespace std;

//O(n2)
// int countPrimes(int n) {
//     if(n==0 || n==1) return 0;
//     if(n==2) return 1;
//     int ans=0;
//     for(int i=2;i<n;i++){
//         bool b=true;
//         for(int j=2;j*j<=i;j++){
//             if(i%j==0){
//                 b=false;
//             }
//         }
//         if(b==true){
//             ans++;
//         }
//     }
//     return ans;  
// }

//O(n)
int countPrimes(int n){
    vector<bool> a(n,true);
    int ans=0;
    for(int i=2;i<n;i++){
        if(a[i]){
            ans++;
        }
        int j=i;
        while(j<n){
            a[j]=false;
            j=j+i;
        }
    }
    return ans;
}

int main(){
    int n=50;
    cout<<countPrimes(n);
}