#include<iostream>
#include<vector>
using namespace std;

void subset(vector<int> &nums,int i,int &ans,int c,int maxm){
    int d=c;
    c=c|nums[i];
    
    if(c==maxm) ans++;
    if(i==nums.size()-1) return;
    
    subset(nums,i+1,ans,c,maxm);
    subset(nums,i+1,ans,d,maxm);
}

int countMaxOrSubsets(vector<int>& nums) {
    int n=nums.size(),maxm=0,ans=0;
    for(int i=0;i<n;i++){
        maxm=maxm|nums[i];
    }
    subset(nums,0,ans,0,maxm);
    return ans;        
}

int main(){
    vector<int> nums={2,2,2};
    cout<<countMaxOrSubsets(nums);
}