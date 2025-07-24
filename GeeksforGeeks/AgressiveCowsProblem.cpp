#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int isvalid(vector <int> arr,int mid,int c){
    int cows=1,laststallpos=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-laststallpos>=mid){
            cows++;
            laststallpos=arr[i];
        }
        if(cows==c){
            return 1;
        }
    }
    return 0;
}
int largestdistance(vector <int> arr,int c){
    sort(arr.begin(),arr.end());
    if(c>arr.size()){
        return -1;
    }
    int st=1,mind=0,end=arr[arr.size()-1]-arr[0];
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isvalid(arr,mid,c)){
            mind=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return mind;
}

int main() {
    vector<int> arr={1,2,8,4,9};
    int c = 3;
    cout<<largestdistance(arr,c);
}