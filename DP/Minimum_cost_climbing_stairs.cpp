#include<bits/stdc++.h>
using namespace std;

int count(int &n, int a){
    if(a >= n){
        if(a == n) return 1;
        return 0;
    }
    return count(n, a + 1) + count(n, a + 2);
}

int minimumcost(int &n){
    int a = 0;
    return count(n, a);
}

int main(){
    int n;
    cin>>n;
    cout<<minimumcost(n)<<endl;
    return 0;
}