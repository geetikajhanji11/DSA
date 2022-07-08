/**************************************************************

LEFT VIEW

Given a binary tree, print the left view of it. Tree is set of 
nodes that are visible when a tree visited from the left side.

         1
      /     \ 
    2        3
  /   \       \ 
4      5       6
    
Ouput: 1 2 4

        1
      /   \ 
     2     3
      \     \ 
       4     6
        \
         5
         
Ouput: 1 2 4 5

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
class Node {
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


// *************** LEFT VIEW PRINT ***************

void levelOrder(Node *root, vector<int> &result) {
    
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);
    result.push_back(root->key);
    
    while(!Q.empty()) {
        
        Node *currNode = Q.front();
        
        if(currNode == NULL) {
            Q.pop();
            if(!Q.empty()) {
                Q.push(NULL);
                Node *nextNode = Q.front();
                result.push_back(nextNode->key);
            }
            continue;
        } 
        
        if(currNode->left != NULL) Q.push(currNode->left);
        if(currNode->right != NULL) Q.push(currNode->right);
        Q.pop();
    }
    
}

vector<int> leftView(Node * root){
    
    vector<int> result;
    
    levelOrder(root, result);
    
    return result;
}

int main() {

    Node* root = new Node(1);
	root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    vector<int> result = leftView(root);
    for(int num : result) {
        cout<<num<<" ";
    }
    
	
	
	return 0;
}