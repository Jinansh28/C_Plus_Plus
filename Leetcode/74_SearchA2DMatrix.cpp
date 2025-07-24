#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int a=matrix.size(),b=matrix[0].size();
    int i=0,st=0,end=a-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(matrix[mid][0]==target || matrix[mid][b-1]==target){
            return true;
        }
        if(matrix[mid][0]>target) end=mid-1;
        if(matrix[mid][b-1]<target) st=mid+1;
        if(matrix[mid][0]<target && matrix[mid][b-1]>target){ 
            i=mid;
            break;
        }
    }
    if (i == a) return false;
    st=0,end=b-1;
    while(st<=end){   
        int mid=st+(end-st)/2;
        if(matrix[i][mid]==target) return true;
        if(matrix[i][mid]>target) end=mid-1;
        else st=mid+1;
    }
    return false;
}

int main(){
    vector<vector<int>> m={{1}};
    int t=1;
    cout<<searchMatrix(m,t);
}