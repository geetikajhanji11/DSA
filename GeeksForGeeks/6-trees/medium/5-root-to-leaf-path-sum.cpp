/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
}; 

bool hasPathSum(Node *root, int S) {
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) {
        return (S - root->data == 0);
    }
    return hasPathSum(root->left, S - root->data) || hasPathSum(root->right, S - root->data);
}

int main() {

    return 0;
}