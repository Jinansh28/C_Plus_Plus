#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        this->data = val;
        this->next = NULL;
    }
};

class queue{
    public:

    node *head, *tail;
    queue(){
        head = tail = NULL;
    }
    
    void enqueue(int val){
        node *str = new node(val);

        if(head == NULL){
            head = tail = str;
        } else{
            tail->next = str;
            tail = str;
        }
    }

    void dequeue(){
        node * str = head;
        if(head == NULL) return;
        else{
            head = head->next;
            str->next = NULL;
        }
        delete(str);
    }

    int front(){
        if(head == NULL) return -1;
        else return head->data;
    }

    int empty(){
        return head == NULL;
    }
};

int main(){
    queue s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    while(!s.empty()){
        cout<<s.front()<<" ";
        s.dequeue();
    }
}
