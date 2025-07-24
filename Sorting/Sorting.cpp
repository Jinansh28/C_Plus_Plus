#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void Selectionsort(vector<int> a){
    for(int i=0;i<a.size()-1;i++){
        int min=i;
        for(int j=i+1;j<a.size();j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}

void BubbleSort(vector<int> a){
    for(int i=0;i<a.size()-1;i++){
        bool isSwap=false;
        for(int j=0;j<a.size()-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                isSwap=true;
            }            
        }
        if(isSwap==false){
            break;
        }
    }
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}


void InsertionSort(vector<int> a){
    for(int i=1;i<a.size();i++){
        int cur=a[i],prev=i-1;
        while(prev>=0 && a[prev]>cur){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=cur;
    }
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}
void merge(vector<int>&a,int st,int mid,int end){
    vector<int> temp;
    int i=st,j=mid+1;
    while(i<=mid && j<=end){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(a[j]);
        j++;
    }
    for(int c=0;c<temp.size();c++){
        a[c+st]=temp[c];
    }
}
void MergeSort(vector<int>&a,int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        MergeSort(a,st,mid);
        MergeSort(a,mid+1,end);
        merge(a,st,mid,end);
    }
}

int partition(vector<int> &a,int st,int end){
    int pivot=a[end];
    int idx=st-1,j=st;
    while(j<end){
        if(a[j]<pivot){
            idx++;
            swap(a[j],a[idx]);
        }
        j++;
    }
    swap(a[++idx],a[end]);
    return idx;
}
void QuickSort(vector<int>&a,int st,int end){
    if(st<end){
        int pvtidx=partition(a,st,end);
        QuickSort(a,st,pvtidx-1);
        QuickSort(a,pvtidx+1,end);
    }
}

void countSort(vector<int>a,int k){
    vector<int> arr(k+1,0);
    vector<int> output(a.size(),0);
    for(int i=0;i<a.size();i++){
        arr[a[i]]++;
    }
    for(int i=1;i<k+1;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=a.size()-1;i>=0;i--){
        output[arr[a[i]]-1]=a[i];
        arr[a[i]]--;
    }
    for(int i:output){
        cout<<i<<" ";
    }
}
int main(){
    vector<int> a={3,2,3,3,2,3,2,3,3,1};
    BubbleSort(a);
    Selectionsort(a);
    InsertionSort(a);
    // MergeSort(a,0,9);
    QuickSort(a,0,9);
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    countSort(a,3);
}