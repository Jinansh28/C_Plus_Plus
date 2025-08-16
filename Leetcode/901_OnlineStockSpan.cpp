#include<iostream>
#include<stack>
using namespace std;

int idx=-1;
stack<pair<int,int>> s;

int next(int price) {
        idx++;
        int span = 1;
        while(!s.empty() && s.top().first <= price){
            s.pop();
        }
        if(s.empty()){
            span = idx+1;
        }
        else{
            span = idx - s.top().second;
        }
        s.push({price,idx});
        return span;
    }

int main(){

}