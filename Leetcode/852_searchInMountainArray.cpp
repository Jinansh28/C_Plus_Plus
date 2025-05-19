#include <iostream>
#include <vector>
using namespace std;

//3,5,3,2,0
// int peakIndexInMountainArray(vector<int>& a) {
//     int st=0,end=a.size()-1;
//     while(st<=end){
//         int mid=st+(end-st)/2;
//         if(mid==0){
//             if(a[1]<a[0]){
//                 return 0;
//             }
//             mid=1;
//         }
//         else if(mid==a.size()-1){
//             if(a[mid]>a[mid-1]){
//                 return mid;
//             }
//             mid=mid-1;
//         }
//         if(mid!=0 && mid!=a.size()-1){
//           if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
//             return mid;
//           }
//           else if(a[mid]>a[mid-1] && a[mid]<a[mid+1]){
//             st=mid+1;
//           }
//           else if(a[mid]<a[mid-1] && a[mid]>a[mid+1]){
//             end=mid-1;
//           }
//         }
//     }
//     return -1;
// }


// Array will always be a mountain array
int peakIndexInMountainArray(vector<int>& a) {
    int st=1,end=a.size()-2;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(a[mid]>a[mid-1] && a[mid]>a[mid+1]){
            return mid;
        }
        else if(a[mid]>a[mid-1] && a[mid]<a[mid+1]){
            st=mid+1;
        }
        else if(a[mid]<a[mid-1] && a[mid]>a[mid+1]){
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums={3,5,3,2,1};
    cout<<peakIndexInMountainArray(nums);
}