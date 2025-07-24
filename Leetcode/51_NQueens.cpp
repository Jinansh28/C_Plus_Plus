#include<iostream>
#include<vector>
using namespace std;

int issafeColumn(vector<string> s,int n,int j){
    for(int i=0;i<n;i++){
        if(s[i][j]=='Q') return 0;
    }
    return 1;
}

int issafeDiagnol(vector<string>& s, int n, int i, int j) {
    for(int k=i-1,l=j-1;k>=0 && l>=0;k--,l--){
        if(s[k][l]=='Q') return 0;
    }
    for(int k=i-1,l=j+1;k>=0 && l<n;k--,l++){
        if(s[k][l]=='Q') return 0;
    }
    return 1;
}

void NQueens(vector<string> &s,vector<vector<string>>& ans,int n,int i){
    if(i==n){
        ans.push_back(s);
        return;
    }
    for(int j=0;j<n;j++){
        if(issafeColumn(s,n,j) && issafeDiagnol(s,n,i,j)){
            s[i][j]='Q';
            NQueens(s,ans,n,i+1);
            s[i][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> s(n,string(n,'.'));
    vector<vector<string>> ans;
    NQueens(s,ans,n,0);
    return ans;
}

int main(){
    vector<vector<string>> s=solveNQueens(3);
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s[i].size();j++){
            cout<<s[i][j]<<endl;
        }
        cout<<endl<<endl;
    }
}