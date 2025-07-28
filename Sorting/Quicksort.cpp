#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &a,int pvt,int st,int end){
    int idx=st-1;
    for(int i=st;i<end;i++){
        if(a[i]<=pvt){
            swap(a[i],a[++idx]);
        }
    }
    swap(a[++idx],a[end]);
    return idx;
}

void quicksort(int st,int end,vector<int> &a){
    if(st<end){
        int pvtidx=partition(a,a[end],st,end);
        quicksort(st,pvtidx-1,a);
        quicksort(pvtidx+1,end,a);
    }
}

int main(){
    vector<int> a={5,2,6,4,1,3};
    quicksort(0,5,a);
    for(auto i: a){
        cout<<i<<" ";
    }
}