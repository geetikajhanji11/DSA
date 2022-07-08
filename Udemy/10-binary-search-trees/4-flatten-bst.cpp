/******************************************************************************

FLATTEN THE BST

Given a BST, convert it to a sorted linked list. The right pointer should
behave as next pointer for the linked list


                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /
           4  7   13
           
    Output = 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> 10 -> 13 -> 14

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

// print flattened BST
void printFlattenedBST(Node *root) {
    cout<<"\nFLATTENED BST: ";
    while(root != NULL) {
        cout<<root->key<<" ";
        root = root->right;
    }
}

// ************* FLATTENED BST *************
// pair => {head, tail}
pair<Node*, Node*> flattenBST(Node * root){
    
    // if we reach NULL node
    if(root == NULL) return {NULL, NULL};
    
    // rec case
    auto leftPair = flattenBST(root->left);
    auto rightPair = flattenBST(root->right);
    
    Node* leftHead = leftPair.first;
    Node* leftTail = leftPair.second;
    
    Node* rightHead = rightPair.first;
    Node* rightTail = rightPair.second;
    
    // if we reach leaf node
    if(leftHead == NULL && rightHead == NULL) {
        return {root, root}; 
    }
    
    // if there is no right subtree
    if(rightHead == NULL) {
        leftTail->right = root;
        return {leftHead, root};
    }
    
    // if there is no left subtree
    if(leftHead == NULL) {
        root->right = rightHead;
        return {root, rightTail};
    }
    
    // if we have both subtrees
    leftTail->right = root;
    root->right = rightHead;
    return {leftHead, rightTail};
    
}

int main() {

    Node *root = NULL;
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    auto p = flattenBST(root);
    printFlattenedBST(p.first);
    
    
    return 0;
}
