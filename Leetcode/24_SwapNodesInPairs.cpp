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

// Recursion
// ListNode* swapPairs(ListNode* head) {
//     if(head == NULL || head->next == NULL) return head;

//     ListNode *curr = head ,*s = head->next ,*p = s->next;
//     s->next = curr;
//     curr->next = swapPairs(p);

//     return s;    
// }

//Loop
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode *curr = head,*prev = NULL,*s = head->next,*p = s->next;
    while(curr != NULL && s != NULL){
        p = s->next;
        curr->next = p;
        s->next = curr;
        if(prev == NULL) head = s;
        else prev->next = s;
        prev = curr;
        curr = p;
        if(p != NULL){
            s = p->next;
        }
        else{
            s = NULL;
        }
    }   
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

    head=swapPairs(head);
    print(head);
}