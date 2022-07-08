/**************************************************************

PRINT AT LEVEL K

Print all nodes at distance K from the root node

        1
      /   \ 
    2      3
  /   \     \ 
4      5     6
     /        
    7
    
k = 3
Ouput = 4, 5, 6

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

// *************** PRINT AT LEVEL K ***************
void printAtLevelK(node *root, int k) {
    
    if(root == NULL) return;
    if(k == 0) {
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
}

int main() {

    node *root = buildTree();
    cout<<"\nPrint at level k\n";
    printAtLevelK(root, 2);
	return 0;
}