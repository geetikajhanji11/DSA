/******************************************************************************

LOWEST COMMON ANCESTOR

Given a Binary Search Tree and values of two nodes that lie inside 
the tree, find the Lowest Common Ancestor (LCA).

Let T be a rooted tree. The lowest common ancestor between two nodes 
n1 and n2 is defined as the lowest node in T that has both n1 and n2 
as descendants (where we allow a node to be a descendant of itself)

You may assume that beth the values exist in the tree and are unique.


                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /  \
           4  7   13  15

    a = 4, b = 7
    Output = 6


*******************************************************************************/

#include <iostream>
#include<vector>
#include<climits>
#include<cstdlib>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

// insert in a BST
node* insert(node *root, int data) {
    
    if(root == NULL) {
        node *newNode = new node(data);
        return newNode;
    }
    
    if(data <= root->data) {
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
    cout<<root->data<<" ";
    inorder(root->right);
}

// ************* LCA *************

node *lcaUtil(node* root, int a, int b) {
    
    // case 1: if we found a node of a or b directly
    // while searching, it means a or b is a child
    // of b or a respectively, so root is returned
    if(root->data == a || root->data == b) return root;
    
    // case 2: a > root AND b > root
    // LCA will lie in right subtree
    if(a > root->data && b > root->data) {
        return lcaUtil(root->right, a, b);
    }
    
    // case 2: a < root AND b < root
    // LCA will lie in left subtree
    else if(a < root->data && b < root->data) {
        return lcaUtil(root->left, a, b);
    }
    
    // case 3: a < root < b
    // then root itself is LCA
    else if(a < root->data && b > root->data) {
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

/*

                8
              /  \
            3     10 
           / \     \
          1  6      14
            / \    /  \
           4  7   13  15
*/

int main() {

    node *root = NULL;
    vector<int> arr{ 8, 3, 10, 1, 6, 14, 4, 7, 13, 15 };
    for(int num : arr) {
        root = insert(root, num);
    }
    
    cout<<"\nINORDER TRAVERSAL: ";
    inorder(root);
    
    
    node* result = lca(root, 4, 7);
    cout<<"\nLCA = ";
    if(result != NULL) {
        cout<<result->data;
    } else {
        cout<<"\nNone.";
    }
    
    
    return 0;
}
