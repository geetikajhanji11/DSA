/**************************************************************

TREE DIAMETER O(N)

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

// ************** DIAMETER OPTIMIZED **************
class HDPair {
    public:
        int height;
        int diameter;
};

// diameter of tree
HDPair diameter(node *root) {
    
    HDPair p;
    
    if(root == NULL) {
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    
    HDPair left = diameter(root->left);
    HDPair right = diameter(root->right);
    
    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;
    
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(d1, max(d2, d3));
    
    return p;
    
}


int main() {

    node *root = buildTree();
    
    HDPair p = diameter(root);
    cout<<"\nDiameter of tree = "<<p.diameter;
    

	return 0;
}