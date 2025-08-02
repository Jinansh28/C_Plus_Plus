#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> m;
    int c=0,a=0;
    for(int i=0;i<arr.size();i++){
        a=0;
        for(int j=i;j<arr.size();j++){
            a=a|arr[j];
            if(m.find(a)==m.end()){
                m.insert(a);
                c++;
            }
        }
    }
    return c;
}

int main(){
    vector<int> arr={1,2,4};
    cout<<subarrayBitwiseORs(arr);
}