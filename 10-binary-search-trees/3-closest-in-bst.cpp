/******************************************************************************

CLOSEST IN BST

Function to find the integer closest to a given target value in a BST.


                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /
           4  7   13
           
    Target Value = 16
    Output = 14

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

// ************* CLOSEST IN BST *************
int closestInBST(Node * root, int key){
    
    int minDiff = INT_MAX;
    int result = 0;
    
    while(root != NULL) {
        
        int diff = abs(key - root->key);
        
        // update difference
        if(diff < minDiff) {
            minDiff = diff;
            result = root->key;
        }    
        
        // go right or left
        if(key <= root->key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    return result;
    
}

int main() {

    Node *root = NULL;
    
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    int key = 17;
    int closest = closestInBST(root, key);
    cout<<"\nclosest to "<<key<<" = "<<closest;
    
    
    return 0;
}
