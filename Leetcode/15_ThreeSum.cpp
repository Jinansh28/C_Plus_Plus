#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;

//O(n3*logm)
// vector<vector<int>> threeSum(vector<int>& nums){
//     vector<vector<int>> ans;
//     set<vector<int>> m;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 if(nums[i]+nums[j]+nums[k]==0){
//                     vector<int> a={nums[i],nums[j],nums[k]};
//                     sort(a.begin(),a.end());
//                 if(m.find(a)==m.end()){
//                     m.insert(a);
//                     ans.push_back(a);
//                 }
//                 }
//             }
//         }
//     }
//     return ans;
// }


//O(n2logm)
// vector<vector<int>> threeSum(vector<int>& nums){
//     set<vector<int>> o;
//     int n=nums.size();
//     for(int i=0;i<n;i++){
//         set<int> m;
//         for(int j=i+1;j<n;j++){
//             int val=0-nums[i]-nums[j];
//             if(m.find(val)!=m.end()){
//                 vector<int>a={nums[i],val,nums[j]};
//                 sort(a.begin(),a.end());
//                 o.insert(a);
//             }
//             m.insert(nums[j]);
//         }
//     }
//     vector<vector<int>> ans(o.begin(),o.end());
//     return ans;
// }

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int a=-nums[i];
        int j=i+1,k=n-1;
        while(j<k){
            int c=nums[j]+nums[k];
            if(c==a){
                vector<int> b={nums[i],nums[j],nums[k]};
                ans.push_back(b);
                while(j<k && nums[j]==nums[j+1])j++;
                while(j<k && nums[k]==nums[k-1])k--;
                j++;
                k--;
            }
            else if(c>a) k--;
            else j++;
        }
    }
    return ans; 
}


int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    vector<vector<int>> ans=threeSum(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}