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

int Sum(node *root){
    if(root == NULL) return 0;
    return Sum(root->left)+Sum(root->right)+root->data;
}

int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,6,7,-1,-1,-1,-1,-1};
    node *root = buildTree(preOrder);
    cout<<Sum(root);
}