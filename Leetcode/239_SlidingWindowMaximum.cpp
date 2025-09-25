#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector <int> ans;
    deque <pair<int,int>> q;
    for(int i = 0 ;i < nums.size(); i++){
        int a = nums[i];
        if(q.empty()) q.push_back({i,a});
        else if (a >= q.front().second){
            q.push_front({i,a});
        }
        else if (a <= q.back().second) q.push_back({i,a});
        else{
            while(a > q.back().second) q.pop_back();
            q.push_back({i,a});
        }
        if(i>=k-1) {
            while(q.front().first <= i-k) q.pop_front();
            ans.push_back(q.front().second); 
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,1,2,0,5};
    vector<int> ans = maxSlidingWindow(nums, 3);
    for(auto i : ans){
        cout<<i<<" ";
    }
}