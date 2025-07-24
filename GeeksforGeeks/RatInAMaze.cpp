#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solution(vector<vector<int>> &maze,int i,int j,vector<string> &ans,int n,string &a){
    if(i==n && j==n){
        ans.emplace_back(a);
        return;
    }
    if(i<n && maze[i+1][j]==1){
        a.push_back('D');
        maze[i][j]=0;
        solution(maze,i+1,j,ans,n,a);
        a.pop_back();
        maze[i][j]=1;
    }
    if(j>0 && maze[i][j-1]==1){
        a.push_back('L');
        maze[i][j]=0;
        solution(maze,i,j-1,ans,n,a);
        a.pop_back();
        maze[i][j]=1;
    }
    if(j<n && maze[i][j+1]==1){
        a.push_back('R');
        maze[i][j]=0;
        solution(maze,i,j+1,ans,n,a);
        a.pop_back();
        maze[i][j]=1;
    }
    if(i>0 && maze[i-1][j]==1){
        a.push_back('U');
        maze[i][j]=0;
        solution(maze,i-1,j,ans,n,a);
        a.pop_back();
        maze[i][j]=1;
    }
    return ;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<string> ans;
    string a;
    int n=maze.size()-1;
    if(maze[0][0]==0 || maze[n][n]==0) return ans;
    solution(maze,0,0,ans,n,a);
    return ans;
}

int main(){

    vector<vector<int>> maze= {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans=ratInMaze(maze);
    for(auto i:ans){
        cout<<i<<" ";
    }
}