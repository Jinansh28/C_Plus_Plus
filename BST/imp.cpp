#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left, *right;

    Node(int data){
        this->val = data;
        left = right = NULL;
    }
};

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int idx = 0;
Node *createBST( Node *root, int data){
    if(root == NULL) return new Node(data);

    if(root->val > data){
        root->left =  createBST(root->left, data);
    }

    else root->right = createBST(root->right ,data);
    
    return root;
}

Node * search (Node *root, int val){
    if(root == NULL) return NULL;
    if(root->val == val) return root;

    if(root->val > val) search(root->left, val);
    else search(root->right, val);
}

Node * del (Node * root, int key){
    if(root == NULL) return NULL;

    if(key< root->val){
        root->left = del(root->left, key);
    }
    else if(key > root->val){
        root->right = del(root->right, key);
    }

    else {
        if(root->left == NULL && root->right == NULL){
            delete root; 
            return NULL;
        }

        else if(root->left != NULL && root->right == NULL){
            delete root;
            return root->left;
        }

        else if(root->left == NULL && root->right != NULL){
            delete root;
            return root->right;
        }

        else{
            Node * str = root->right;
            
            while(str->left != NULL){
                str = str->left;
            }

            root->val = str->val;
            str->val = -1;
            root->right = del(root->right , -1);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = NULL;

    for(int data : arr){
        root = createBST(root, data);
    }
    inorder(root);
    cout<<endl;

    Node * str = search(root, 6);
    if(str) cout<<true<<endl;
    else cout<<false<<endl;

    del(root, 3);
    inorder(root);
}