#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;
    
    node(int val){
        this->data = val;
        left = right = NULL;
    }
};

static int idx = -1;
node *buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx] == -1) return NULL;

    node *root = new node(preorder[idx]);
    root->left  = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preorder(node *root){
    if(root == NULL){
        // cout<<-1<<" ";
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL){
        // cout<<-1<<" ";
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void morrisInorderTraversal (node* root){
    node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        
        else{
            node* pd = curr->left;
            while(pd-> right != NULL && pd->right != curr){
                pd = pd->right;
            }

            if(pd->right == NULL){
                pd->right = curr;
                curr = curr->left;
            }

            else{
                pd->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,6,7,-1,-1,-1,-1,-1};
    node *root = buildTree(preOrder);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    morrisInorderTraversal(root);
}