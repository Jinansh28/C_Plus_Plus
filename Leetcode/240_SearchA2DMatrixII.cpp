#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int a=matrix.size(),b=matrix[0].size();
    int st=0,end=b-1;
    while(st<a && end>=0){
        if(matrix[st][end]==target) return true;
        else if(matrix[st][end]>target) end--;
        else st++;
    }
    return false;
}


int main(){
    vector<vector<int>> m={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int t=55;
    cout<<searchMatrix(m,t);
}