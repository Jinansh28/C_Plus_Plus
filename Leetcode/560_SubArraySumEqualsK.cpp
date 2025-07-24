#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


//O(n2)
// int subarraySum(vector<int>& nums, int k) {
//     int ans=0;
//     int n=nums.size();
//     int tsum=0;
//     for(int i=0;i<n;i++){
//         tsum+=nums[i];
//     }
//     for(int i=0;i<n;i++){
//         int sum=tsum;
//         for(int j=n-1;j>=i;j--){
//             if(sum==k) ans++;
//             sum-=nums[j];
//         }
//         tsum-=nums[i];
//     }
//     return ans;   
// }

//O(n)
int subarraySum(vector<int>&nums,int k){
    unordered_map<int,int> m;
    m[0]=1;
    int sum=0,n=nums.size(),ans=0,a=k;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(m.find(sum-k)!=m.end()) ans+=m[sum-k];
        m[sum]++;
    }
    return ans;
}

int main(){
    vector<int> nums={-1,-1,1};
    int k=0;
    cout<<subarraySum(nums,k);
}