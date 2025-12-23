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



void countnodes(node *root,int &a){
    if(root == NULL) return;
    a++;
    countnodes(root->left,a);
    countnodes(root->right,a);
}

int CountNodes(node *root){
    if(root == NULL) return 0;
    return CountNodes(root->left)+CountNodes(root->right)+1;
}


int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,6,7,-1,-1,-1,-1,-1};
    node *root = buildTree(preOrder);
    cout<<CountNodes(root);
}