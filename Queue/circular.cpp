#include<iostream>
using namespace std;

class circularq{
    private:
    int *arr;
    int cap,currSize;
    int f,r;
    public:
    circularq(int size){
        cap = size;
        arr = new int(cap);
        f = 0, r = -1;
        currSize = 0;
    }

    void push(int data){
        if(currSize == cap){
            cout<<" Queue Full ";
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data; 
        currSize++;
    }

    void pop(){
        if(empty()){
            cout<<" Queue Empty ";
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }

    int front(){
        if(empty()){
            cout<<" Queue Empty ";
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }

};

int main(){
    circularq Q(3);
    Q.push(1);
    cout<<Q.front()<<" ";
    Q.push(2);
    cout<<Q.front()<<" ";
    Q.push(3);
    cout<<Q.front()<<" ";
    Q.push(4);
    Q.pop();
    cout<<Q.front()<<" ";
    Q.pop();
    cout<<Q.front()<<" ";
    Q.pop();
    cout<<Q.front()<<" ";
}