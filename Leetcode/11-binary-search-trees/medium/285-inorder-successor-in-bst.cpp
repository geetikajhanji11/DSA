/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* getInorderSuccessor(TreeNode* root) {
    if(root->left == NULL) return root;
    return getInorderSuccessor(root->left);
}

void getInorderSuccessor(TreeNode* root, TreeNode* p, TreeNode* &successor) {
    if(root->val > p->val) {
        successor = root;
    }

    if(root == p) return;

    if(p->val < root->val) {
        getInorderSuccessor(root->left, p, successor);
    } else {
        getInorderSuccessor(root->right, p, successor);
    }
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root == NULL || p == NULL) return NULL;
    if(p->right != NULL) {
        return getInorderSuccessor(p->right);
    }
    TreeNode* successor = NULL;
    getInorderSuccessor(root, p, successor);
    return successor;
}

int main() {

    return 0;
}