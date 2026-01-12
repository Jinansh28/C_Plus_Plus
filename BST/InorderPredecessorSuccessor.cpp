#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int data) {
        val = data;
        left = right = NULL;
    }
};

/* 👉 WRITE YOUR FUNCTION HERE */
void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key) {
    if(root == NULL) return;
    if(root->val > key){
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    else if(root->val < key){
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    } 
    else {
        if(pre == NULL){
        TreeNode *a = root->left;
            if(a != NULL) while(a->right != NULL) a = a->right;
            pre = a;
        }
        if(suc == NULL){
            TreeNode *b = root->right;
            if(b != NULL) while(b->left != NULL) b = b->left;
            suc = b;
        }
    }
    return;
}

/* -------- TESTING CODE -------- */
int main() {

    /*
            50
           /  \
         30    70
        /  \   / \
      20   40 60  80
    */

    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    int key = 35;

    TreeNode* pre = NULL;
    TreeNode* suc = NULL;

    findPreSuc(root, pre, suc, key);

    if(pre)
        cout << "Predecessor: " << pre->val << endl;
    else
        cout << "Predecessor: NULL\n";

    if(suc)
        cout << "Successor: " << suc->val << endl;
    else
        cout << "Successor: NULL\n";

    return 0;
}
