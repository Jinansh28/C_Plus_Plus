#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//     int n=grid.size();
//     vector<int> a(n*n+1,0) ;
//     vector<int> ans(2,0);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             a[grid[i][j]]+=1;
//         }
//     }
//     for(int i=0;i<n*n;i++){
//         if(a[i]==0){
//             ans[0]=i;
//         }
//         if(a[i]==2){
//             ans[1]=i;
//         }
//     }
//     return ans;
// }

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n=grid.size(),sum=(n*n)*(n*n+1)/2;
    vector<int> ans(2,0);
    unordered_set<int> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int val = grid[i][j];
            if(m.find(val)!=m.end()){
                ans[0]=val;
            }
            sum-= val;
            m.emplace(val);
        }
    }
    ans[1]=sum;
    return ans;
}


int main(){
    vector<vector<int>> grid={{1,2},{3,2}};
    findMissingAndRepeatedValues(grid);
}