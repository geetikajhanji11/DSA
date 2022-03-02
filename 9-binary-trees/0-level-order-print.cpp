/**************************************************************

BINARY TREE

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

// level order print (LINE WISE PRINT)
void levelOrderLine(node* root) {
    
    cout<<"\nLEVEL ORDER (LINE WISE PRINT)\n";
    
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    
    while(!Q.empty()) {
        
        node *n = Q.front();
        if(n == NULL) {
            cout<<"\n";
            Q.pop();
            
            if(!Q.empty()) Q.push(NULL);
            
            continue;
        }
        
        cout<<n->data<<" ";
        if(n->left != NULL) Q.push(n->left);
        if(n->right != NULL) Q.push(n->right);
        
        Q.pop();
    }
    
}


int main() {

    node *root = buildTree();
    levelOrder(root);
    levelOrderLine(root);

	return 0;
}