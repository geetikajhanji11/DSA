/**************************************************************

TREE DIAMETER O(N^2)

Find the diameter of the binary tree.
Diameter is defined as the largest distance between any two
nodes of the tree.

        1
      /   \ 
    2      3
  /   \     \ 
4      5     6
     /        
    7

Largest Diameter = 5

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

// level order print (LINEAR PRINT)
void levelOrder(node* root) {
    
    cout<<"\nLEVEL ORDER (LINEAR PRINT)\n";
    
    queue<node*> Q;
    Q.push(root);
    
    while(!Q.empty()) {
        node *n = Q.front();
        
        cout<<n->data<<" ";
        
        if(n->left != NULL) Q.push(n->left);
        if(n->right != NULL) Q.push(n->right);
        
        Q.pop();
    }
}

// height of tree
int height(node* root) {
    
    if(root == NULL) return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

// diameter of tree
int diameter(node *root) {
    
    if(root == NULL) return 0;
    
    int d1 = height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    
    return max(d1, max(d2, d3));
    
}



int main() {

    node *root = buildTree();
    levelOrder(root);
    
    int h = height(root);
    cout<<"\nHeight of tree = "<<h;
    
    int d = diameter(root);
    cout<<"\nDiameter of tree = "<<d;
    

	return 0;
}