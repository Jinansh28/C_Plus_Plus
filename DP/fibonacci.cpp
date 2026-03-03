#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int> &dp){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != 0) return dp[n];
    dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n];
}

int fibonaccibottomup(int n){
    vector<int> dp1(n+1, 0);
    dp1[0] = 0;
    dp1[1] = 1;

    for(int i = 2 ; i <= n ; i++){
        dp1[i] = dp1[i-1] + dp1[i-2];
    }
    return dp1[n];
}

int fibonaccispace(int n){
    if(n == 0) return 0;
    int prev1 = 1, prev2 = 0;
    for(int i = 2 ; i <= n ; i++){
        int a  = prev1 + prev2;
        prev2 = prev1;
        prev1 = a;
    }
    return prev1;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    cout<<fibonacci(n, dp)<<endl;
    cout<<fibonaccibottomup(n)<<endl;
    cout<<fibonaccispace(n);
    return 0;
}