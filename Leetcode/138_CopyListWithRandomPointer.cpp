#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<int,int> m;
        Node *str=head;
        Node *head2=new Node(str->val);
        Node *prev=head2;
        str=str->next;
        while(str!=NULL){
            Node *temp=new Node(str->val);
            str=str->next;
            prev->next=temp;
            prev=temp;
        }
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n2->next = n3;

    n1->random = n3;
    n2->random = n1;
    n3->random = nullptr;

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "\nCopied List:\n";
    printList(copied);

    return 0;
}
