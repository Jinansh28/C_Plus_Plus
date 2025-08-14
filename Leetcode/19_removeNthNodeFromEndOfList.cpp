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

// two loops
// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     ListNode *str = head;
//     int count = 0;
//     while(str != NULL){
//         count++;
//         str = str->next;
//     }

//     if(count < n) return NULL;
//     if(count == n) return head->next;
//     ListNode *p,*q,*temp;
//     str = head;
//     int a = 1;
//     while(str != NULL){
//         if(a == count-n) p = str;
//         a++;
//         str = str->next;
//     }
//     temp = p->next;
//     q = temp->next;
//     temp->next == NULL;
    
//     p->next = q;
//     delete(temp);
//     return head;
// }


//Single loop
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *str = head,*temp,*q,*p = head;
    int count = 0;
    while(str != NULL){
        if(count>n){
            p = p->next;
        }
        count++;
        str = str->next;
    }
    if(count==n) return head->next;
    temp = p->next;
    q = temp->next;
    temp->next == NULL;
    
    p->next = q;
    delete(temp);
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

    head=removeNthFromEnd(head,3);
    print(head);
}