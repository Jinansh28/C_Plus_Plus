#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    node *head;
    node *tail;

    public:
    list(){
        head=tail=NULL;
    }
    void print(){
        node *str=head;
        while(str!=NULL){
            cout<<str->data<<" ";
            str=str->next;
        }
    }

    void push_front(int val){
        if(head==NULL){
            node *str= new node(val);
            head=tail=str;
            return;
        }
        else{
            node *str=new node(val);
            str->next=head;
            head=str;
        }
    }

    void pop_front(){
        if(head!=NULL){
            node *str=head;
            head=head->next;
            delete(str);
        }
    }

    void push_back(int val){
        if(tail==NULL){
            push_front(val);
        }
        else{
            node *str= new node(val);
            tail->next=str;
            tail=str;
        }
    }

    void pop_back(){
        if(tail==NULL) return;
        if(tail==head){
            delete head;
            head=tail=NULL;
            return;
        }
        node *str=head;
        while(str->next!=tail){
            str=str->next;
        }
        str->next=NULL;
        node*st=tail;
        tail=str;
        delete(st);
    }

    void insert(int val,int pos){
        if(pos<0) return;
        if(pos==0) push_front(val);
        node *s=head;
        node *str=new node(val);
        int i=0;
        while(i<pos-1){
            s=s->next;
            i++;
        }
        str->next=s->next;
        s->next=str;
    }

};

int main(){
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.pop_back();
    ll.push_front(4);
    ll.push_back(5);
    ll.pop_front();
    ll.insert(4,2);
    ll.print();
}