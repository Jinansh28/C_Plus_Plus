#include<bits/stdc++.h>
using namespace std;

int MaximumSumRec(vector<int> &arr, int n){
    if(n == 0) return arr[n];
    if(n < 0) return 0;

    int pick = MaximumSumRec(arr, n-2) + arr[n];
    int notpick = MaximumSumRec(arr, n-1);
    return max(pick, notpick);
}

int Maximum(vector<int> &arr, int n, vector<int> &dp){
    if(n == 0) return arr[n];
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    int pick = MaximumSumRec(arr, n-2) + arr[n];
    int notpick = MaximumSumRec(arr, n-1);
    
    dp[n] = max(pick, notpick);
    return dp[n];
}

int MaximumSumMem(vector<int> &arr, int n){
    vector<int> dp(n+1, -1);
    return Maximum(arr, n, dp);
}

int MaximumSumTab(vector<int> &arr, int n){
    vector<int> dp (n + 1, -1);
    dp[0] = arr[0];
    for(int i = 1 ; i <= n ; i++){
        int a = (i-2 >= 0) ? dp[i-2] : 0;
        dp[i] = max(dp[i-1], a + arr[i]);
    }
    return dp[n];
}

int MaximumSumSpace(vector<int> &arr, int n){
    int prev1 = arr[0], prev2 = 0;
    for(int i = 0 ; i < n ; i++){
        int a = max(prev1, prev2 + arr[i]);
        prev2 = prev1;
        prev1 = a;
    }
    return max(prev2,prev1);
}

int main(){
    vector<int> arr = {9, 8, 9, 1, 1, 1, 10, 1, 1, 1, 40, 1};
    int n = arr.size();
    cout<<MaximumSumRec(arr, n-1)<<endl;
    cout<<MaximumSumMem(arr, n-1)<<endl;
    cout<<MaximumSumTab(arr, n-1)<<endl;
    cout<<MaximumSumSpace(arr, n-1)<<endl;
}