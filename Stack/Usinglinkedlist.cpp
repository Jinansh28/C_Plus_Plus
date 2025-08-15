#include<iostream>
#include<list>
using namespace std;

class stack{
    list<int> ll;
    public:
    int top(){
        return ll.front();
    }
    void push(int n){
        ll.push_front(n);
    }
    void pop(){
        ll.pop_front();
    }
    bool empty(){
        return ll.size() == 0;
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