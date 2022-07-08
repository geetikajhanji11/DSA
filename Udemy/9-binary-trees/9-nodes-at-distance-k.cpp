/**************************************************************

NODES AT DISTANCE K

Print all nodes at distance K from the target node

        1
      /   \ 
    2      3
  /   \     \ 
4      5     6
     /  \     
    7    8
        / \
       9  10    
    
target node = 5
k = 2
Ouput = [1, 4, 9, 10]

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

// *************** NODES AT DISTANCE K ***************
void printAtLevelK(node *root, int k, vector<int> &result) {
    
    if(root == NULL) return;
    if(k == 0) {
        result.push_back(root->data);
        return;
    }
    printAtLevelK(root->left, k-1, result);
    printAtLevelK(root->right, k-1, result);
}

int distanceFromTarget(node *root, node *target, int k, vector<int> &result) {
    
    // base case
    if(root == NULL) {
        return -1;
    }
    
    // CASE-1: if we found the target node
    if(root == target) {
        printAtLevelK(root, k, result);
        return 0;
    }
    
    // CASE-2: if target is in left subtree
    int DL = distanceFromTarget(root->left, target, k, result);
    if(DL != -1) {
        
        // print current root node
        if(DL + 1 == k) {
            result.push_back(root->data);
        } 
        
        // print some nodes in the right subtree
        else {
            printAtLevelK(root->right, k-2-DL, result);
        }
        
        return 1 + DL;
    }
    
    // CASE-3: if target is in right subtree
    int DR = distanceFromTarget(root->right, target, k, result);
    if(DR != -1) {
        
        // print current root node
        if(DR + 1 == k) {
            result.push_back(root->data);
        } 
        
        // print some nodes in the left subtree
        else {
            printAtLevelK(root->left, k-2-DR, result);
        }
        
        return 1 + DR;
    }
    
    // if DL and DR both == -1, we return -1
    return -1;
}

vector<int> nodesAtDistanceK(node *root, node *target, int k) {
    
    vector<int> result;
    
    distanceFromTarget(root, target, k, result);
    
    sort(result.begin(), result.end());
    
    return result;
}

int main() {

    node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right->left = new node(9);
	root->left->right->right->right = new node(10);
	
	//Target Node 5
	node* target = root->left->right;
	
	vector<int> result = nodesAtDistanceK(root, target, 2);
	for(int num : result) {
	    cout<<num<<" ";
	}
	
	
	return 0;
}