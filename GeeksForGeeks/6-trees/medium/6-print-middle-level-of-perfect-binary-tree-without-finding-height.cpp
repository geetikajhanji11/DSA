/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
   child and a pointer to right child */
struct Node {
    int key;
    struct Node *left, *right;
};
 
/* To create a newNode of tree and return pointer */
struct Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

void dfs(Node* slow, Node* fast) {

    if(fast == NULL || fast->left == NULL) {
        cout<<slow->key<<", ";
        return;
    }

    dfs(slow->left, fast->left->left);
    dfs(slow->right, fast->left->left);

}

void printMiddleLevel(Node* root) {
    dfs(root, root);
}
 
int main() {

    Node* n1 = newNode(1);
    Node* n2 = newNode(2);
    Node* n3 = newNode(3);
    Node* n4 = newNode(4);
    Node* n5 = newNode(5);
    Node* n6 = newNode(6);
    Node* n7 = newNode(7);
 
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n1->left = n2;
    n1->right = n3;
 
    printMiddleLevel(n1);

    return 0;
}