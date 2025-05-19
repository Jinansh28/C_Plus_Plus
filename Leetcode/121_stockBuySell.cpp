#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//O(n^2) Brute Force
// int maxProfit(vector<int> &prices){
//     int maxprofit=0,profit=0;
//     for(int i=0;i<prices.size();i++){
//         for(int j=i+1;j<prices.size();j++){
//             profit=prices[j]-prices[i];
//             if(profit>maxprofit){
//                 maxprofit=profit;
//             }
//         }
//     }
//     return maxprofit;
// }

//Optimised O(n)
int maxProfit(vector<int> prices){
    int max=prices[0],min=prices[0],maxprofit=0,profit=max-min;
    for(int i=0;i<prices.size();i++){
        if(min>prices[i]){
            min=prices[i];
        }
        profit=prices[i]-min;
        if(profit>maxprofit){
            maxprofit=profit;
        }
    }
    return maxprofit;
}

int main(){
    vector <int> prices={7,1,5,3,6,4};
    int a[]={1,2,3};
    int b[]={1,2,3};
    if(memcmp(a,b,3)){
        cout<<0;
    }
    else{
        cout<<1;
    }
    cout<<maxProfit(prices);
}