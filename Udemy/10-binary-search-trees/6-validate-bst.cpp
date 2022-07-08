/******************************************************************************

IS BINARY TREE A BST

https://www.youtube.com/watch?v=s6ATEkipzow&ab_channel=NeetCode

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

// ************* VALIDATE BST *************
bool isBSTUtil(Node *root, int min, int max) {

    if(root == NULL) return true;

    if(min > root->key || root->key > max) {
        return false;
    }
    
    bool isLeftBST = isBSTUtil(root->left, min, root->key);
    bool isRightBST = isBSTUtil(root->right, root->key, max);
    
    return isLeftBST && isRightBST;
}

bool isBST(Node * root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {

    Node *root = NULL;
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    return 0;
}
