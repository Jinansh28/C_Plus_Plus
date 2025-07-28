#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>>& grid,int i,int j,int n,int idx){
    if(grid[i][j]!=idx) return false;
    if(grid[i][j]==(n*n)-1) return true;
        if(i>0 && j>1 && grid[i-1][j-2]==idx+1){
            if(check(grid,i-1,j-2,n,idx+1)) return true;
        }
        if(i>1 && j>0 && grid[i-2][j-1]==idx+1){
            if(check(grid,i-2,j-1,n,idx+1)) return true;
        }
        if(i>1 && j<n-1 && grid[i-2][j+1]==idx+1){
            if(check(grid,i-2,j+1,n,idx+1)) return true;
        }
        if(i>0 && j<n-2 && grid[i-1][j+2]==idx+1){
            if(check(grid,i-1,j+2,n,idx+1)) return true;
        }
        if(i<n-1 && j<n-2 && grid[i+1][j+2]==idx+1){
            if(check(grid,i+1,j+2,n,idx+1)) return true;
        }
        if(i<n-2 && j<n-1 && grid[i+2][j+1]==idx+1){
            if(check(grid,i+2,j+1,n,idx+1)) return true;
        }
        if(i<n-2 && j>0 && grid[i+2][j-1]==idx+1){
            if(check(grid,i+2,j-1,n,idx+1)) return true;
        }
        if(i<n-1 && j>1 && grid[i+1][j-2]==idx+1){
            if(check(grid,i+1,j-2,n,idx+1)) return true;
        }
    return false;
}


bool checkValidGrid(vector<vector<int>>& grid) {
    int i=0,j=0,n=grid.size();
    return check(grid,0,0,n,0);
}

int main(){
    vector<vector<int>> grid={{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout<<checkValidGrid(grid);
}