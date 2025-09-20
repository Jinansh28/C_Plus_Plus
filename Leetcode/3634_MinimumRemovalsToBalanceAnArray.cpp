#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int minRemoval(vector<int>& nums, int k) {
    if(nums.size()==1) return 0;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    if(((long long)nums[0]*k)>=nums[n-1]) return 0;
    int i = 0, maxlen = 0,ans = 0;
    for(int j = 0; j< n ;j++){
        if(((long long)nums[i]*k)<nums[j]) i++;
        if(((long long)nums[i]*k)>=nums[j]){
            maxlen = max(maxlen,j-i);
        }
    }
    return n-maxlen;
}

int main(){
    vector<int> nums={43,71,125,225,327,172,431,194};
    int k=4;
    cout<<minRemoval(nums,k);
}