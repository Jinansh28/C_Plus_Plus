#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n =nums.size();
    vector<int> ans(n,-1);
    stack<int> s;
    
    for(int i = (2*n)-1 ;i >=0; i--){
        int a = nums[i%n];
        while(!s.empty() && s.top() <= a){
            s.pop();
        }
        if(!s.empty()) ans[i%n]=s.top();
        s.push(a);
    }
    return ans;
}


// vector<int> nextGreaterElements(vector<int>& nums) {
//     int n = nums.size();
//     int largest = 0;
//     stack<int> s;

//     for(int i = 0;i < n; i++){
//         if(nums[i] > nums[largest]) largest = i;
//     }
//     s.push(nums[largest]);
//     nums[largest] = -1;
    
//     int b = largest + n -1, i = (b) % n;
//     while(i != largest){
//         int a = nums[i];
//         if(a < s.top()) nums[i] = s.top();
//         else{
//             while(!s.empty() && s.top() <= a){
//                 s.pop();
//             }
//             if(s.empty()) nums[i] = -1;
//             else nums[i] = s.top();
//         }
//         s.push(a);
//         b--;
//         i = (b)%n;
//     }
    
//     return nums;
// }


int main() {
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums);

    cout << "Result: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}