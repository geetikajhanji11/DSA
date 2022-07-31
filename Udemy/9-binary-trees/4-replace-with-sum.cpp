/**************************************************************

REPLACE WITH SUM

Given a binary tree, replace every node by sum of all its 
descendants, leaf nodes intact.

        1
      /   \ 
    2      3
  /   \     \ 
4      5     6
     /        
    7
    
    turns into
    
        27
      /   \ 
    16      6
  /   \     \ 
4      7     6
     /        
    7


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

// ************** REPLACE WITH SUM **************

int replace_with_sum(node* root) {

    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;

    int left_sum = replace_with_sum(root->left);
    int right_sum = replace_with_sum(root->right);

    int data = root->data;
    root->data = left_sum + right_sum;

    return data + root->data; 
}

// **********************************************
class sumPair {
    public:
        int data;   // current element
        int sum;    // totalSum of this current element's subtree
};

// basic idea:
// we need to add the "data" and "sum"
// of both the left and right nodes together.
sumPair replaceWithSum(node* root) {
    
    sumPair p;
    
    // base case
    if(root == NULL) {
        p.data = 0;
        p.sum = 0;
        return p;
    }
    
    // rec case
    sumPair left = replaceWithSum(root->left);
    sumPair right = replaceWithSum(root->right);
    
    int totalSum = left.data + left.sum + right.data + right.sum;
    
    // making the pair
    p.data = root->data;
    p.sum = totalSum;
    
    // -- UPDATING NODE DATA --
    // totalSum == 0 means that it is root node
    // in question, we need root nodes to stay intact
    // that is why we don't update it
    if(totalSum != 0) root->data = totalSum;
    
    // outputting
    cout<<"\npair: "<<p.data<<", "<<p.sum;
    
    return p;
    
}

// ************** REPLACE WITH SUM **************
// Prateek Solution
int replaceWithSumSol(node* root) {
    
    // base case
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->data;
    
    // recursive case
    int data = root->data;
    int sum = replaceWithSumSol(root->left) + replaceWithSumSol(root->right); // left sum + right sum
    
    // update node
    root->data = sum;
    
    return sum + data;
}


int main() {

    node *root = buildTree();
    
    replaceWithSum(root);
    
    cout<<"\n";
    levelOrderLine(root);

	return 0;
}