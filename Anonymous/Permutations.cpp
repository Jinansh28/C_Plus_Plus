#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void count(vector<int> &arr,int &c,unordered_set <int> &m,int a,int i){
    if(i==arr.size()) return;
    int b=a|arr[i];
    if(m.find(b)==m.end()){
        m.insert(b);
        c++;
    }
    count(arr,c,m,b,i+1);
    count(arr,c,m,a,i+1);
}

int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set <int> m;
    int c=0;
    count(arr,c,m,0,0);
    return c;
}

int main(){
    vector<int> arr={1,2,4};
    cout<<subarrayBitwiseORs(arr);
}