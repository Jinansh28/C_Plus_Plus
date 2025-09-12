#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map <int,int> m;
    
    for(int i=0;i<nums2.size();i++){
        m.insert({nums2[i],i});
    }
    
    for(int j=0;j<nums1.size();j++){
        nums1[j]=m[nums1[j]];
    }
    
    stack <int> s;
    
    for(int i = nums2.size()-1;i >= 0; i--){
        int a = nums2[i];
            while(!s.empty() && a>s.top()) s.pop();
            if(s.empty()) nums2[i] = -1;
            else nums2[i] = s.top();
        s.push(a);
    }
    for(int i=0;i<nums1.size();i++){
        nums1[i]=nums2[nums1[i]];
    }
    return nums1;
}
int main(){
    vector<int> nums1={1,4,2},nums2={1,3,4,2};
    nextGreaterElement(nums1,nums2);
}



















