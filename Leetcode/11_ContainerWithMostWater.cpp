#include<iostream>
#include<vector>
using namespace std;

//Brute Force
// int maxArea(vector<int>& height) {
//     int area=0,maxa=0;
// for(int i=0;i<height.size()-1;i++){
//     for(int j=i+1;j<height.size();j++){
//         int a=j-i;
//         int b=min(height[i],height[j]);
//         area=a*b;
//         maxa=max(area,maxa);
//     }
// }
// return maxa;
// }

    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,area,maxA=0,e=0;
        while(i<j){
            int a=j-i;
            int b=min(height[i],height[j]);
            area=a*b;
            if(min(height[i+1],height[j])>b){
                i++;
            }
            else{
                j--;
            }
            maxA=max(maxA,area);
        } 
        return maxA;
    } 

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}