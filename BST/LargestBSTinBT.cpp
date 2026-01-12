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

class Info {
    public:
    int min,max,size;
     
    Info(int mi, int ma, int sz){
        min = mi;
        max = ma;
        size = sz;
    }
};

Info helper (TreeNode *root){
    if(root == NULL) return Info(INT_MAX,INT_MIN,0);

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->val > left.max && root->val < right.min){
        int currmin = min(left.min, root->val);
        int currmax = max(right.max, root->val);
        int currsize = left.size + right.size + 1;

        return Info(currmin,currmax,currsize);
    }

    return Info(INT_MIN,INT_MAX,max(left.size,right.size));
}

int largestBST(TreeNode* root) {
    Info info = helper(root);
    return info.size;
}


int main() {

    /*
            50
           /  \
         30    60
        / \   /  \
       5  20 45  70
                    \
                     80
    */

    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);
    root->right->right->right = new TreeNode(80);

    cout << "Largest BST size: " << largestBST(root) << endl;

    return 0;
}
