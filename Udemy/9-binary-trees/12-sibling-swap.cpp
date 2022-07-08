/**************************************************************

BINARY TREE SIBLING SWAP

Given a binary tree, write an efficient algorithm to determine 
if it can be converted into another binary tree by doing any 
number of swaps of its right and left branches.

**************************************************************/
#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Function to determine if two given binary trees can be transformed
// into each other by doing any number of left and right subtree swaps
bool equal(Node* X, Node* Y)
{
    // base case: both trees are the same (handles the case when both trees are empty)
    if (X == Y) {
        return true;
    }
 
    return (X && Y) && (X->data == Y->data) &&
        ((equal(X->left, Y->left) && equal(X->right, Y->right)) ||
        (equal(X->right, Y->left) && equal(X->left, Y->right)));
}
 
int main()
{
    // construct the first tree
    Node* X = nullptr;
 
    X = new Node(6);
    X->left = new Node(3);
    X->right = new Node(8);
    X->left->left = new Node(1);
    X->left->right = new Node(7);
    X->right->left = new Node(4);
    X->right->right = new Node(2);
    X->right->left->left = new Node(1);
    X->right->left->right = new Node(7);
    X->right->right->right = new Node(3);
 
    // construct the second tree
    Node* Y = nullptr;
 
    Y = new Node(6);
    Y->left = new Node(8);
    Y->right = new Node(3);
    Y->left->left = new Node(2);
    Y->left->right = new Node(4);
    Y->right->left = new Node(7);
    Y->right->right = new Node(1);
    Y->left->left->left = new Node(3);
    Y->left->right->left = new Node(1);
    Y->left->right->right = new Node(7);
 
    if (equal(X, Y)) {
        cout << "Binary tree can be converted";
    }
    else {
        cout << "Binary tree cannot be converted";
    }
 
    return 0;
}