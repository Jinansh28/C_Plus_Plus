#include<iostream>
#include<vector>
using namespace std;

void merge(int st,int end,int mid,vector<int> &a){
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(a[i]<=a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i<=mid) temp.push_back(a[i++]);
    while(j<=end) temp.push_back(a[j++]);
    for(int c=0;c<temp.size();c++){
        a[c+st]=temp[c];
    }
}

void mergesort(int st,int end,vector<int> &a){
    if(st<end){
        int mid=st+(end-st)/2;
        mergesort(st,mid,a);
        mergesort(mid+1,end,a);
        merge(st,end,mid,a);
    }
}

int main(){
    vector<int> a={1,5,4,3,2};
    mergesort(0,4,a);
    for(auto i:a){
        cout<<i<<" ";
    }
}