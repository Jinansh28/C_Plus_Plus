#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};

class Circularlist{
    Node *head;
    Node *tail;
    public:

    Circularlist(){
        head=tail=NULL;
    }

    void push_front(int data){
        Node *str=new Node(data);
        if(head==NULL){
            head=tail=str;
            tail->next=head;
        }
        else{
            str->next=head;
            head=str;
            tail->next=head;
        }
    }

    void push_back(int data){
        Node *str=new Node(data);
        if(head==NULL){
            head=tail=str;
            tail->next=head;
        }
        else{
            tail->next=str;
            tail=str;
            tail->next=head;
        }
    }

    void pop_front(){
        if(tail==NULL) return;
        if(tail->next==tail){
            delete(tail);
            tail=head=NULL;
            return;
        }
        Node *str=tail->next;
        Node *s=str->next;
        tail->next=s;
        head=s;
        delete(str);
    }

    void pop_back(){
        if(tail==NULL) return;
        if(tail->next==tail){
            delete(tail);
            tail=head=NULL;
            return;
        }
        Node *str=tail->next;
        while(str->next!=tail){
            str=str->next;
        }
        str->next=tail->next;
        delete(tail);
        tail=str;
    }

    void print(){
        Node *str=head;
        cout<<head->val<<" ";
        str=str->next;
        while(str!=head){
            cout<<str->val<<" ";
            str=str->next;
        }
    }

};

int main(){
    Circularlist ll;
    ll.push_front(10);
    ll.push_front(9);
    ll.push_front(11);
    ll.push_back(12);
    ll.push_front(10);
    ll.push_front(9);
    ll.push_front(11);
    ll.push_back(12);
    ll.print();
    cout<<"\n";
    ll.pop_back();
    ll.pop_front();
    ll.print();
}