#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int minRemoval(vector<int>& nums, int k) {
    if(nums.size()==1) return 0;
    sort(nums.begin(),nums.end());
    if(((long long)nums[0]*k)>=nums[nums.size()-1]) return 0;
    int n=nums.size(),ans=n,c=0,a=n;
    for(int i=0;i<n;i++){
        c=i;
        for(int j=n-1;j>=i;j--){
            if((long long)nums[i]*k>=nums[j]){
                ans=min(ans,c);
            }
            else{
                c++;
            }
        }
        a=min(a,c);
    }
    if(ans!=n) return ans;
    return a;    
}

int main(){
    vector<int> nums={43,71,125,225,327,172,431,194};
    int k=4;
    cout<<minRemoval(nums,k);
}