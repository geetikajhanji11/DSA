/**************************************************************

VERTICAL ORDER PRINT

Given a binary tree, we need to print it vertically.

         1
      /     \ 
    2        3
  /   \    /   \ 
4      5  6     7
           \     \
            8     9
    
Ouput:
4
2
1   5   6
3   8
7
9

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


// *************** VERTICAL ORDER PRINT ***************

void vertical(node* root, int position, int &lowest, unordered_map<int, vector<int>> &mp) {
    
    // base case
    if(root == NULL) return;
    
    // keeps track of lowest negative value
    // for easy map traversal because 
    // unordered_map does not store keys
    // in ascending order
    lowest = min(lowest, position);
    
    // update the nodes vector at position
    vector<int> nodes = mp[position];
    nodes.push_back(root->data);
    mp[position] = nodes;
    
    // recursive case
    vertical(root->left, position - 1, lowest, mp);
    vertical(root->right, position + 1, lowest, mp);
    
}

void verticalOrderPrint(node *root) {
    
    // map => key: position, value: nodes at position
    int lowest = 0;
    unordered_map<int, vector<int>> mp;
    
    vertical(root, 0, lowest, mp);
    
    // iterate from lowest -ve value
    // upto max position stored as key in map
    int position = lowest;
    while(mp.find(position) != mp.end()) {
        vector<int> nodes = mp[position];
        for(int n : nodes) {
            cout<<n<<" ";
        }
        cout<<endl;
        position++;
    }
}

int main() {

    node* root = new node(1);
	root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    verticalOrderPrint(root);
	
	
	return 0;
}