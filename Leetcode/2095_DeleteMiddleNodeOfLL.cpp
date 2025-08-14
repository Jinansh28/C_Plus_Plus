#include<iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *head){
    ListNode *s = head;

    while(s != NULL){
        cout<<s->val<<" ";
        s = s->next;
    }

}

ListNode* deleteMiddle(ListNode* head) {
    if(head->next == NULL) return NULL;
    
    ListNode *p = head,*q = head,*prev = NULL;
    while(p != NULL && p->next !=NULL){
        prev = q;
        p = p->next->next;
        q = q->next;
    }
    p = q->next;
    q->next = NULL;
    prev->next = p;
    delete(q);
    return head;
}


int main(){
    ListNode *head = new ListNode(1);
    ListNode *s1 = new ListNode(2);
    ListNode *s2 = new ListNode(3);
    ListNode *s3 = new ListNode(4);
    ListNode *s4 = new ListNode(5);
    ListNode *s5 = new ListNode(6);

    head->next = s1;
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = s5;
    s5->next = NULL;

    head=deleteMiddle(head);
    print(head);
}