#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//Unoptimised
// void solution(int &sum,set <vector<int>> &s,vector<int> &candidates,int target,vector<int> a,int idx){
//     if(sum>target) return;
//     if(sum==target){
//         sort(a.begin(),a.end());
//         s.insert(a);
//         return;
//     }
//     for(int i=0;i<candidates.size();i++){
//         if(i<idx) continue;
//         idx=i;
//         sum+=candidates[i];
//         a.push_back(candidates[i]);
//         solution(sum,s,candidates,target,a,idx);
//         sum-=candidates[i];
//         a.pop_back();
//     }
//     return;
// }

// vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//     int sum=0,idx;
//     set <vector<int>> s;
//     vector<int> a;
//     solution(sum,s,candidates,target,a,idx);
//     vector<vector<int>> ans(s.begin(),s.end());
//     return ans;
// }

//Optimal
void solution(int sum,vector<vector<int>> &ans,vector<int> &candidates,int target,vector<int> a,int idx){
    if(sum>target) return;
    if(sum==target){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<candidates.size();i++){
        sum+=candidates[i];
        a.push_back(candidates[i]);
        solution(sum,ans,candidates,target,a,i);
        sum-=candidates[i];
        a.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int sum=0,idx=0;
    vector<int> a;
    vector<vector<int>> ans;
    solution(sum,ans,candidates,target,a,idx);
    return ans;
}

int main(){
    vector<int> candidates={2,3,6,7};
    int target=7;
    vector<vector<int>> a=combinationSum(candidates,target);
    for(int i=0;i<a.size();i++){
        for (auto j:a[i]){
            cout<<j;
        }
        cout<<" ";
    }
}