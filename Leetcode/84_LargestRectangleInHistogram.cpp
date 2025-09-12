#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> left,right;
    vector<int> prevsmall,nextsmall;
    int area=0,maxarea=0;
    for(int i=0;i<heights.size();i++){
        int a = heights[i];
        while(!left.empty() && heights[left.top()] >= a){
            left.pop();
        }
        if(left.empty()) prevsmall.push_back(-1);
        else prevsmall.push_back(left.top());
        left.push(i);
    }
   
    for(int i=heights.size()-1;i>=0;i--){
        int a = heights[i];
        while(!right.empty() && heights[right.top()] >= a){
            right.pop();
        }
        if(right.empty()) nextsmall.push_back(heights.size());
        else nextsmall.push_back(right.top());
        right.push(i);
    }
    reverse(nextsmall.begin(),nextsmall.end());
    
    for(int i=0;i<heights.size();i++){
        area = max(heights[i],(nextsmall[i]-prevsmall[i]-1)*heights[i]);
        maxarea = max(maxarea,area);
    }
    return maxarea;
}

int main(){
    vector<int> heights = {2, 1, 2, 1, 2, 1, 2};
    cout<<largestRectangleArea(heights);
}