#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int val){
        this->val=val;
        prev=next=child=NULL;
    }
};

void ans(Node *s,Node *&p){
    if(s==NULL) return;
    Node *str=new Node(s->val);
    p->next=str;
    str->prev=p;
    p=str;
    ans(s->child,p);    
    ans(s->next,p);
    return;
}

Node* flatten(Node* head) {
    Node *s=head;
    Node *p=new Node(-1);
    Node *head2=p;
    ans(s,p);
    Node *dummy=head2;
    head2=head2->next;
    if (head2) head2->prev = nullptr;
    delete(dummy);
    return head2;
}

void print(Node *head){
    Node *s=head;
    while(s!=NULL){
        cout<<s->val<<" ";
        s=s->next;
    }
}



int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Level 2 (child of 3): 7-8-9-10
    Node* n7  = new Node(7);
    Node* n8  = new Node(8);
    Node* n9  = new Node(9);
    Node* n10 = new Node(10);

    n7->next = n8;  n8->prev = n7;
    n8->next = n9;  n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    n3->child = n7; // Link child

    // Level 3 (child of 8): 11-12
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n11->next = n12; n12->prev = n11;

    n8->child = n11; // Link child
    // Flatten
    Node* flatHead = flatten(n1);

    // Print
    print(flatHead);

    return 0;
}

// Node *ans(Node *s,Node *p){
//     if(s==NULL) return NULL;
//     Node *str=new Node;
//     str->val=s->val;
//     str->child=str->next=str->prev=NULL;
//     p->next=str;
//     str->prev=p;
//     p=str;

//     if(ans(s->child,p)!=NULL){
//             p->next=ans(s->child,p);
//             p=p->next;
//         }
//     if(ans(s->next,p)!=NULL){
//             p->next=ans(s->next,p);
//             p=p->next;
//         }

//     return p; 
// }

// Node* flatten(Node* head) {
//     Node *s=head;
//     Node *p=new Node;
//     p->val=-1;
//     p->next=p->prev=NULL;
//     Node *head2=p;
//     head2=ans(s,p);
//     return head2;
// }