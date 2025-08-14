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

ListNode* swapNodes(ListNode* head, int k) {
    if(head->next == NULL) return head;

    ListNode *str = head;
    int n = 0;
    while(str != NULL){
        str = str->next;
        n++;
    }

    int a = 1;
    str = head;
    ListNode *p,*q;
    while(a<=n){
        if(a == k) p = str;
        if(a == n-k+1) q = str;
        a++;
        str = str->next;
    }
    int temp = p->val;
    p->val = q->val;
    q->val = temp;
    
    return head;
}

// ListNode* swapNodes(ListNode* head, int k) {
//     if(head->next == NULL) return head;

//     ListNode *str = head;
//     int n = 0;
//     while(str != NULL){
//         str = str->next;
//         n++;
//     }

//     if(n == 2){
//         ListNode *p = head,*q = p->next;
//         q->next = p;
//         p->next = NULL;
        
//         return q;
//     }

//     if(k+1 == n-k) return head;

//     if(n/2 == k){
//         ListNode *p,*q,*p1,*q1;
//         int a=1;
//         while(a<=n){
//         if(a == k-1) p = str;
//         if(a == n-k+1) q = str;
//         a++;
//         str = str->next;
//         }
//         p1 = p->next;
//         q1 = p1->next;
//         p->next = q1;
//         q1->next = p1;
//         p1->next = q;
//         return head;
//     }
    
//     if(k == 1){
//         ListNode *prev = head;
//         while(prev->next->next != NULL){
//             prev = prev->next;
//         }
//         ListNode *curr= prev->next;
//         ListNode *s = head->next;
//         head->next = NULL;
//         prev->next = head;
//         curr->next = s;
//         return curr;
//     }

//     int a = 1;
//     str = head;
//     ListNode *p,*q,*p1,*q1,*p2,*q2;
//     while(a<=n){
//         if(a == k-1) p = str;
//         if(a == n-k) q = str;
//         a++;
//         str = str->next;
//     }
//     p1 = p->next;
//     p2 = p1->next;
//     q1 = q->next;
//     q2 = q1->next;

//     q1->next = NULL;
//     p1->next = NULL;
//     p->next = q1;
//     q1->next = p2;
//     q->next = p1;
//     p1->next = q2;
//     return head;
// }

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

    head=swapNodes(head,1);
    print(head);
}