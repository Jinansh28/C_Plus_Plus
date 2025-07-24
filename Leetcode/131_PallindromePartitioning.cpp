#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int ispallindrome(string str){
    string p=str;
    reverse(p.begin(),p.end());
    return p==str;
}

void solution(string s,vector<vector<string>> &ans,vector<string> &a,int i){
    if(i>=s.size()){
        ans.push_back(a);
        return;
    }
    for(int j=i;j<s.size();j++){
        string str=s.substr(i,j-i+1);
        if(ispallindrome(str)){
            a.push_back(str);
            solution(s,ans,a,j+1);
            a.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s) {
    int i=0;
    vector<vector<string>> ans;
    vector<string> a;
    solution(s,ans,a,i);
    return ans;
}

int main(){
    string s="aab";
    vector<vector<string>> a=partition(s);
    for(int i=0;i<a.size();i++){
        for(auto j:a[i]){
            cout<<j<<",";
        }
        cout<<" ";
    }
}