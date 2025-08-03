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

ListNode *detectCycle(ListNode *head) {
    if(head==NULL || head->next==NULL) return NULL;
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(slow!=fast) return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }    
    return slow;    
}

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.head=detectCycle(ll.head);
    cout<<ll.head->data;
}