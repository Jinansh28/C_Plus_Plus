#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left,*right;

    TreeNode(int data){
        this->val = data;
        left = right = NULL;
    }
};

TreeNode *createBST(TreeNode *root,int data){
    if(root == NULL) return new TreeNode(data);

    if(root->val > data) root->left = createBST(root->left, data);
    else root->right = createBST(root->right,data);

    return root;
}

void inorder(TreeNode *root,vector<int> &a){
    if(root == NULL) return;

    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
}

TreeNode *sortedArraytoBST(vector<int> &nums,int l,int r){
    if(l>r) return NULL;

    int mid = l+(r-l)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArraytoBST(nums,l,mid-1);
    root->right = sortedArraytoBST(nums,mid+1,r);

    return root;
}

TreeNode *mergeBST(TreeNode *p, TreeNode *q){
    vector<int> a,b;
    inorder(p,a);
    inorder(q,b);
    
    int m = a.size(), n = b.size(),l = m+n;
    for(int i = m ; i < l ; i++){
        a.push_back(-1);
    }
    int i = l-1;
    for( ; i >= 0 && m > 0 && n > 0; i--){
        if(a[m-1] > b[n-1]){ 
            a[i] = a[m-1];
            m--;
        }
        else{
            a[i] = b[n-1];
            n--;
        }
    }

    while(m>0){
        a[i] = a[m-1];
        i--;
        m--;  
    }

    while(n>0){
        a[i] = b[n-1];
        i--;
        n--;
    }

    l = 0;
    int  r = a.size()-1;

    TreeNode *root = sortedArraytoBST(a,l,r);

    return root;
}

void Inorder(TreeNode *root){
    if(root == NULL) return;
    Inorder(root->left);
    cout<<root->val<<" ";
    Inorder(root->right);
}


int main(){
    vector<int> arr1 = {8,1,2,10}; 
    vector<int> arr2 = {5,3,0};
    
    TreeNode *root1 = NULL,*root2 = NULL;

    for(int data: arr1){
        root1 =  createBST(root1, data);
    }
    Inorder(root1);
    for(int data: arr2){
        root2 =  createBST(root2, data);
    }
    cout<<endl;
    Inorder(root2);

    TreeNode *root = mergeBST(root1,root2);
    Inorder(root);
}