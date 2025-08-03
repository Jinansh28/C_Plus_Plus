#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
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
            cout<<str->val;
            str=str->next;
        }
    }
};


// Space not optimised loops
// ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//     ListNode *head=new ListNode(-1);
//     ListNode*temp=head;
//     if(list1==NULL && list2==NULL) return NULL;
//     if(list1==NULL) return list2;
//     if(list2==NULL) return list1;
//     while(list1!=NULL && list2!=NULL){
//         if(list1->data<=list2->data){
//             ListNode *str= new ListNode(list1->data);
//             temp->next=str;
//             temp=str;
//             list1=list1->next;
//         }
//         else{
//             ListNode *str= new ListNode(list2->data);
//             temp->next=str;
//             temp=str;
//             list2=list2->next;
//         }
//     }
//     if(list1!=NULL){
//         while(list1!=NULL){
//             ListNode *str= new ListNode(list1->data);
//             temp->next=str;
//             temp=str;
//             list1=list1->next;
//         }
//     } 
//     if(list2!=NULL){
//         while(list2!=NULL){
//             ListNode *str= new ListNode(list2->data);
//             temp->next=str;
//             temp=str;
//             list2=list2->next;
//         }
//     }
//     return head->next; 
// }


//Recursion better space complexity

ListNode* merge(ListNode *list1,ListNode *list2,ListNode *temp){
    if(list1==NULL && list2==NULL) return NULL;
    if(list1==NULL){
        temp->next=list2;
        merge(list1,list2->next,list2);
        return NULL;
    }
    if(list2==NULL){
        temp->next=list1;
        merge(list1->next,list2,list1);
        return NULL;
    }
    if(list1->val<=list2->val){
        temp->next=list1;
        merge(list1->next,list2,list1);
    }
    else{
        temp->next=list2;
        merge(list1,list2->next,list2);
    }
    return NULL;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL && list2==NULL) return NULL;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    ListNode dummy=ListNode(0);
    ListNode *temp=&dummy;
    if(list1->val<=list2->val){
        temp->next=list1;
        merge(list1->next,list2,list1);
    }
    else{
        temp->next=list2;
        merge(list1,list2->next,list2);
    }
    
    return dummy.next;
}


int main(){
    list ll1,ll2,ll;
    ll1.push_back(1);
    ll1.push_back(3);
    ll1.push_back(5);
    ll1.push_back(7);
    ll1.push_back(9);
    ll2.push_back(2);
    ll2.push_back(4);
    ll2.push_back(6);
    ll2.push_back(8);
    ll2.push_back(10);
    ll.head=mergeTwoLists(ll1.head,ll2.head);
    ll.print();
}