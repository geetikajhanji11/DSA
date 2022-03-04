/******************************************************************************

SPECIAL BST

Given a special kind of BST, where every node also contains a pointer
to the parent node.
You have to find the next inorder successor of a given target node of
that tree. The root node of the tree is not given. Return NULL if the
inorder succe3ssor doesnt exist.

                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /
           4  7   13

Target node = 7  
Output = 8

*******************************************************************************/


#include<iostream>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

Node* findInOrderSuccessor( Node *inputNode ){
    
    // if the right subtree is NOT NULL
    // find the left most child of right subtree if it exists
    if(inputNode->right != NULL) {
        Node* temp = inputNode;
        temp = temp->right;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }
    
    // if the right subtree is NULL
    // traverse the parent till node is a right child of its parent
    Node* parent = inputNode->parent;
    Node* child = inputNode;
    while(parent != NULL && parent->right == child) {
        child = parent;
        parent = child->parent;
    }
    
    return parent;
    
}