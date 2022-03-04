/******************************************************************************

SHORTEST TREE PATH

Given a Binary Search Tree and values of two nodes that lie inside 
the tree, find the Shortest Path Length between the two nodes


                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /  \
           4  7   13  15

Shortest Distance Between (4, 7) = 2
Shortest Distance Between (6, 13) = 5
Shortest Distance Between (7, 15) = 6


*******************************************************************************/

#include <iostream>
#include<vector>
#include<climits>
#include<cstdlib>
using namespace std;

class node {
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

// insert in a BST
node* insert(node *root, int data) {
    
    if(root == NULL) {
        node *newNode = new node(data);
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
void inorder(node* root) {
    if(root == NULL) return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

// ************* LCA *************

node *lcaUtil(node* root, int a, int b) {
    
    // case 1: if we found a node of a or b directly
    // while searching, it means a or b is a child
    // of b or a respectively, so root is returned
    if(root->key == a || root->key == b) return root;
    
    // case 2: a > root AND b > root
    // LCA will lie in right subtree
    if(a > root->key && b > root->key) {
        return lcaUtil(root->right, a, b);
    }
    
    // case 2: a < root AND b < root
    // LCA will lie in left subtree
    else if(a < root->key && b < root->key) {
        return lcaUtil(root->left, a, b);
    }
    
    // case 3: a < root < b
    // then root itself is LCA
    else if(a < root->key && b > root->key) {
        return root;
    }
    
    // if none of the other cases match
    return NULL;
}

node* lca(node* root, int a, int b){
    
    // a should be less than b
    // for logic to work
    if(b < a) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    return lcaUtil(root, a, b);
    
}

// ************* SHORTEST TREE PATH *************
int shortestDist(node * root, int a, int b){
   
    node* lcaNode = lca(root, a , b);
    node* temp = NULL;
    
    int ctr = 0;
    
    // finding length from lca to a
    temp = lcaNode;
    while(temp->key != a) {
        ctr++;
        if(a < temp->key) temp = temp->left;
        else temp = temp->right;
    }
    
    // finding length from lca to b
    temp = lcaNode;
    while(temp->key != b) {
        ctr++;
        if(b < temp->key) temp = temp->left;
        else temp = temp->right;
    }
    
    
    return ctr;
    
}

/*

                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /  \
           4  7   13  15
           
Shortest Distance Between (4, 7) = 2
Shortest Distance Between (6, 13) = 5
Shortest Distance Between (7, 15) = 6
*/

int main() {

    node *root = NULL;
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13, 15 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    
    int result = shortestDist(root, 7, 15);
    cout<<"\nShortest Distance = "<<result;
    
    
    
    return 0;
}
