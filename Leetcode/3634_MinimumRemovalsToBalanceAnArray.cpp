#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int minRemoval(vector<int>& nums, int k) {
        if(nums.size()==1) return 0;
        sort(nums.begin(),nums.end());
        if((nums[0]*k)>=nums[nums.size()-1]) return 0;
        int ans=0,a=0,count=INT_MAX;
        int i=0,j=nums.size()-1;
        int g=INT_MAX;
        bool f=false;
        while(i<j){
            if((nums[i]*k)==nums[j]){
                if(ans<count) count=ans;
                f=true;
                break;
            }
            else if((nums[i]*k)>nums[j]){
                g=ans;
                break;
            }
            if(a%2==0){
                a++;
                i++;
                ans++;
            }
            else{
                a++;
                j--;
                ans++;
            }
        }
        i=0,j=nums.size()-1;
        a=0,ans=0;
        while(i<j){
            if((nums[i]*k)==nums[j]){
                if(ans<count) count=ans;
                return count;
            }
            else if((nums[i]*k)>nums[j] ){
                if(ans<g) g=ans;
                if(f==true) return count;
            }
            if(a%2==1){
                a++;
                i++;
                ans++;
            }
            else{
                a++;
                j--;
                ans++;
            }
        }
        if(g<100000){
            return g;
        }
        if(i>=j){
            return ans;
        }
        
        return count;
    }

int main(){
    vector<int> nums={10,11,30};
    int k=2;
    cout<<minRemoval(nums,k);
}