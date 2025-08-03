#include<iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode *next;
    ListNode(int val){
        data=val;
        next=NULL;
    }
};

class list{
    public:
    ListNode *head;
    list(){
        head=NULL;
    }
    void push_back(int val){
        ListNode *str=new ListNode(val);
        if(head==NULL) head=str;
        else{
            ListNode *s=head;
            while(s->next!=NULL){
                s=s->next;
            }
            s->next=str;
        }
    }
    void print(){
        ListNode *str=head;
        while(str!=NULL){
            cout<<str->data;
            str=str->next;
        }
    }
};

bool hasCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return false;
    ListNode *p=head;
    ListNode *q=head;
    while(q!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
        if(p==q) return true;
    }
    return false;
}

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    cout<<hasCycle(ll.head);
}