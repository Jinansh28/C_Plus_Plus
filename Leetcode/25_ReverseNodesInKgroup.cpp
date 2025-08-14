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

// ListNode* reverseKGroup(ListNode* head, int k) {
//     if(head->next == NULL) return head;
//     ListNode *end = head, *curr = head, *prev = NULL, *s = head->next, *st = head,*p;

//     for(int i = 1;i < k; i++){
        
//         end = end->next;
//         if(end == NULL){
//             return head;
//         }
//         cout<<".";
//     }

//     while(curr != end){
//         curr->next = prev;
//         prev = curr;
//         curr = s;
//         s = s->next;
//         cout<<"*";
//     }

//     curr->next = prev;
//     head = curr;

//     while(1){
//         end = s;
//         for(int i = 1;i < k; i++){
            
//             end = end->next;
//             if(end == NULL){
//                 st->next = s;
//                 return head;
//             }
//             cout<<".";
//         }

//         prev = NULL;
//         curr = s;
//         s = s->next;
//         p = curr;
//         while(curr != end ){
//             curr->next = prev;
//             prev = curr;
//             curr = s;
//             s = s->next;
//             cout<<"*";
//         }
//         curr->next = prev;
//         st->next = curr;
//         st = s;

//         end = s;
//         for(int i = 1;i < k; i++){
//             end = end->next;
//             if(end == NULL){
//                 p->next = s;
//             return head;
//         }
//             cout<<".";
//         }

//         prev = NULL;
//         curr = s;
//         s = s->next;
//         while(curr != end ){
//             curr->next = prev;
//             prev = curr;
//             curr = s;
//             s = s->next;
//             cout<<"*";
//         }
//         curr->next = prev;
//     }
    
//     return head;
// }

ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    if(k==1) return head;
    
    ListNode *str = head,*prev = NULL,*curr = head,*s = head->next;
    for(int i=1;i<k;i++){
        str = str->next;
        if(str == NULL) return head;
    }

    while(curr != str){
        curr->next = prev;
        prev = curr;
        curr = s;
        s = s->next;
    }
    
    curr->next = prev;
    ListNode *p = curr;

    head->next = reverseKGroup(s,k);
    return curr;
}

void print(ListNode *head){
    ListNode *s = head;

    while(s != NULL){
        cout<<s->val<<" ";
        s = s->next;
    }

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

    head=reverseKGroup(head,2);
    print(head);
}