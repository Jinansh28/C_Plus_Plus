#include<iostream>
#include<vector>
#include<queue>
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
        cout<<-1<<" ";
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL){
        cout<<-1<<" ";
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node *root){
    if(root == NULL){
        cout<<-1<<" ";
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node *root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *curr = q.front();
        q.pop();

        if(curr == NULL && !q.empty()){
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        else if(curr == NULL && q.empty()) break;
        cout<<curr->data<<" ";
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}


int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *root = buildTree(preOrder);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
}
