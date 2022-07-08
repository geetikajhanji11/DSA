/******************************************************************************

SEARCH

Implement a function that checks whether an element is present
in BST or not. Traverse only one branch of tree. Complexity
should be O(H) not O(N)

*******************************************************************************/

#include <iostream>
#include<vector>
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

// ************* SEARCH *************
bool isPresent(Node * root, int key){
    
    if(root == NULL) return false;
    
    if(root->key == key) return true;
    
    if(key <= root->key) {
        return isPresent(root->left, key);
    } else {
        return isPresent(root->right, key);
    }
    
}

int main() {

    Node *root = NULL;
    
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    int key = 101;
    if(isPresent(root, key)) {
        cout<<"\nKey is present";
    } else {
        cout<<"\nKey is not presnt";
    }
    
    return 0;
}
