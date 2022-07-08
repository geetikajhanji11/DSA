/**************************************************************

HEIGHT BALANCED O(N)

Given a binary tree, check if it is height balanced.
A non-empty binary tree T is balanced if:
  1.  Left subtree of T is balanced
  2.  Right subtree of T is balanced
  3.  The difference between heights of left subtree
      and right subtree is not more than 1

        1
      /   \ 
    2      3
  /   \     \ 
4      5     6
     /        
    7
    
TRUE


**************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<cstdlib>
#include<algorithm>
using namespace std;

// binary tree node class
class node {
public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree() {
    int data;
    cin>>data;
    
    if(data == -1) return NULL;
    
    node *newNode = new node(data);
    newNode->left = buildTree();
    newNode->right = buildTree();
    
    return newNode;
}

// *************** HEIGHT BALANCED ***************
class nodePair {
    public:
        int height;
        bool isBalanced;
};

nodePair heightBalancd(node* root) {
    
    nodePair p;
    
    // base case
    if(root == NULL) {
        p.height = 0;
        p.isBalanced = true;
        return p;
    }
    
    // rec case
    nodePair left = heightBalancd(root->left);
    nodePair right = heightBalancd(root->right);
    
    int height = max(left.height, right.height) + 1;
    bool isBalanced = left.isBalanced && right.isBalanced && abs(left.height - right.height) <= 1;
    
    p.height = height;
    p.isBalanced = isBalanced;
    
    return p;
}


int main() {

    node *root = buildTree();
    
    nodePair p = heightBalancd(root);
    cout<<"\nHeight of tree: "<<p.height;
    cout<<"\nisBalanced of tree: "<<p.isBalanced;

	return 0;
}