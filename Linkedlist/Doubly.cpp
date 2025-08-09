#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node *prev;
        
        Node(int val){
            this->val=val;
            next=prev=NULL;
        }
};

class Doublylist{
    public:
    Node *head;
    Node *tail;

    Doublylist(){
        head=tail=NULL;
    }

    void push_front(int val){
        if(head==NULL){
            head=new Node(val);
            tail=head;
        }
        else{
            Node *str=new Node(val);
            str->next=head;
            head->prev=str;
            head=str;
        }
    }

    void print(){
        Node *str=head;
        while(str!=NULL){
            cout<<str->val;
            str=str->next;
        }
    }

    void print_back(){
        Node *s=tail;
        while(s!=NULL){
            cout<<s->val;
            s=s->prev;
        }
    }

    void push_back(int val){
        Node *str=new Node(val);
        if(head==NULL){
            head=tail=str;
        }
        else{
            tail->next=str;
            str->prev=tail;
            tail=str;
        }
    }

    Node* pop_back(){
        if(tail==NULL)  return NULL;
        if(tail->prev==NULL){
            delete(tail);
            head=tail=NULL;
            return NULL;
        }
        Node *str=tail;
        tail=tail->prev;\
        tail->next=NULL;
        delete(str);
        return head;
    }

    Node * pop_front(){
        if(head==NULL) return NULL;
        if(head->next==NULL){
            delete(head);
            head=tail=NULL;
            return NULL;
        }
        Node *str=head;
        head=head->next;
        head->prev=NULL;
        delete(str);
        return head;
    }
};

int main(){
    Doublylist l1;
    l1.push_front(1);
    l1.push_front(0);
    l1.push_back(2);

    l1.print();
    cout<<"\n";
    l1.print_back();
    cout<<"\n";

    l1.push_front(1);
    l1.push_front(0);
    l1.push_back(2);

    l1.print();
    cout<<"\n";
    l1.print_back();
    cout<<"\n";
    
    l1.pop_back();
    l1.pop_front();

    l1.print();
    cout<<"\n";
    l1.print_back();
    cout<<"\n";
}