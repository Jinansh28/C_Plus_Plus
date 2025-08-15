#include<iostream>
#include<vector>
using namespace std;

class stack{
    vector <int> v;
    public:

    int top(){
        return v[v.size()-1];
    }
    void push(int n){
        v.push_back(n);
    }
    void pop(){
        v.pop_back();
    }
    bool empty(){
        return v.size()==0;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}