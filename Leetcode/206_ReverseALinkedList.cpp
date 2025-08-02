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

    void print(){
        ListNode *str=head;
        while(str!=NULL){
            cout<<str->data<<" ";
            str=str->next;
        }
    }

    void push_back(int val){
        ListNode *str= new ListNode(val);
        if(head==NULL){
            head=str;
            return;
        }
        else{
            ListNode *s=head;
            while(s->next!=NULL){
                s=s->next;
            }
            s->next=str;
        }
    }
};

ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    else if(head->next->next==NULL){
        ListNode *str=head->next;
        str->next=head;
        head->next=NULL;
        head=str;
        return head;
    }
    ListNode *prev=NULL;
    ListNode *str=head;
    ListNode *s=head->next;
    while(s!=NULL){
        str->next=prev;
        prev=str;
        str=s;
        s=s->next;
    }
    str->next=prev;
    head=str;
    return head;  
}

int main(){
    list ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.print();
    cout<<endl;
    ll.head=reverseList(ll.head);
    ll.print();
}