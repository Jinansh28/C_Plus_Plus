#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;){
            int k=j+1,l=n-1;
            long long a=(long long)target-((long long)nums[i]+(long long)nums[j]);
            while(k<l){
                long long b=(long long)nums[k]+(long long)nums[l];
                if(b==a){
                    vector<int> c={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(c);
                    while(k<l && nums[k]==nums[k+1]) k++;
                    k++;
                    l--; 
                }
                else if(b>a) l--;
                else k++;
            }
            j++;
            while(j<n && nums[j]==nums[j-1])j++;
        }
    }
    return ans;
}

int main(){
    vector<int>nums={2,2,2,2,2,2,2,2};
    int target=8;
    vector<vector<int>> ans=fourSum(nums,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}