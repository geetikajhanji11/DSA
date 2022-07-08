/******************************************************************************

INORDER SUCCESSOR

Given a BST, find the inorder successor of a given target node.


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

#include <iostream>
#include<vector>
#include<climits>
#include<cstdlib>
using namespace std;

class Node {
    public:
    int key;
    Node *left;
    Node *right;
    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

// insert in a BST
Node* insert(Node *root, int data) {
    
    if(root == NULL) {
        Node *newNode = new Node(data);
        return newNode;
    }
    
    if(data <= root->key) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
    
}

// L, D, R
void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

// get node
Node* searchNode(Node * root, int key){
    
    if(root == NULL) return NULL;
    
    if(root->key == key) return root;
    
    if(key <= root->key) {
        return searchNode(root->left, key);
    } else {
        return searchNode(root->right, key);
    }
    
}

// ************* INORDER SUCCESSOR *************
Node* inorderSuccessor(Node* root, Node* target) {
    
    Node* successor = NULL;
    
    // if there is no right subtree
    // traverse from root, and reach
    // the target node while keeping
    // trak of each visited node > target
    if(target->right == NULL) {
        while(root != target) {
            if(root->key > target->key) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
    } 
    
    // if right subtree exists,
    // then go to left most node
    // in the right subtree
    else {
        target = target->right;
        while(target->left != NULL) {
            target = target->left;
        }
        successor = target;
    }
    
    return successor;
    
}

int main() {

    Node *root = NULL;
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    Node* target = searchNode(root, 7);
    Node* successor = inorderSuccessor(root, target);
    
    cout<<"\nInorder Successor of "<<target->key<<" = ";
    if(successor == NULL) {
        cout<<"None.";
    } else {
        cout<<successor->key;
    }
    
    return 0;
}
