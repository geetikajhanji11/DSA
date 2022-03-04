/******************************************************************************

MINIMUM HEIGHT BST

Given a sorted array, construct a BST of minimum height.

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

// L, D, R
void inorder(Node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

// ************* MIN HEIGHT BST *************

Node *minHeightBST(vector<int> arr, int low, int high) {
    
    // base case
    if(low > high) return NULL;
    
    // get mid
    int mid = (low + high) / 2;
    Node *root = new Node(arr[mid]);
    
    // rec case
    root->left = minHeightBST(arr, low, mid-1);
    root->right = minHeightBST(arr, mid+1, high);
        
    return root;
}

int main() {

    Node *root = NULL;
    
    vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    root = minHeightBST(arr, 0, arr.size() - 1);
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    
    return 0;
}
