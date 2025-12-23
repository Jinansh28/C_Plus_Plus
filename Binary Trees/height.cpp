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

void Height (node *root,int a,int &ans){
    if(root == NULL){
        ans = max(ans,a-1);
        return;
    }

    Height(root->left,a+1,ans);
    Height(root->right,a+1,ans);

}

int height (node *root){
    if(root == NULL) return 0;
    int ans = 1;
    Height(root,1,ans);
    return ans;
}

int HeighT(node *root){
    if(root == NULL) return 0;
    return max(HeighT(root->left),HeighT(root->right))+1;
}

void countnodes(node *root,int &a){
    if(root == NULL) return;
    a++;
    countnodes(root->left,a);
    countnodes(root->right,a);
}


int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,6,7,-1,-1,-1,-1,-1};
    node *root = buildTree(preOrder);
    cout<<HeighT(root)<<endl;
    int a = 0;
    countnodes(root,a);
    cout<<a;
}