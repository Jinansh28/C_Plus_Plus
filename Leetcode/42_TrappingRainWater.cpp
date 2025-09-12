#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;


//O(n) Time and O(1) Space
int trap(vector<int>& height) {
    int n =height.size();
    int ans = 0,lmax = 0,rmax = 0,l = 0,r = n-1;
    
    while(l<r){
        lmax = max(lmax,height[l]);
        rmax = max(rmax,height[r]);
        if(lmax<rmax){
            ans += lmax-height[l];
            l++;
        }
        else{
            ans += rmax-height[r];
            r--;
        }
    }
    return ans;
}


//O(n) Time and Space
// int trap(vector<int>& height) {
    
//     int n = height.size(),sum = 0 ,a = height[0];
//     if(n <=2) return 0;

//     vector<int> r,l;
//     l.push_back(a);
//     for(int i = 1;i<n;i++){
//         if(height[i]>a) a = height[i];
//         l.push_back(a);
//     }
//     a = height[n-1];
//     r.push_back(a);
//     for(int i = n-2;i>=0;i--){
//         if(height[i]>a) a = height[i];
//         r.push_back(a);
//     }
//     reverse(r.begin(),r.end());

//     for(int i = 0 ;i < n; i++){
//         sum += (min(l[i],r[i])-height[i]);
//     }
//     return sum;  
// }

int main(){
    vector<int> height = {4,2,0,0,2,0};
    cout<<trap(height);
}