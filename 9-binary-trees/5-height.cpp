/**************************************************************

HEIGHT OF BINARY TREE

**************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
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

// *************** HEIGHT ***************
int height(node* root) {
    
    // base case
    if(root == NULL) return 0;
    
    // rec case
    int left = height(root->left);
    int right = height(root->right);
    
    return max(left, right) + 1;
}


int main() {

    node *root = buildTree();
    
    int h = height(root);
    cout<<"\nHeight of tree: "<<h;

	return 0;
}