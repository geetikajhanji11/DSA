/**************************************************************

MAX SUBSET SUM O(N)

Find the largest sum of a subset of nodes in a binary tree,
such that if a node is included in the sum, then its parent
and children must not be included in the subset sum

        1
      /   \ 
    2      3
  /   \     \ 
4      5     6
     /        
    7
    
Max Sum = 18
If we pick 4, 7, 6, 1 => we get 18


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

// *************** MAXIMUM SUBSET SUM TREE ***************
class nodePair {
    public:
        int include;
        int exclude;
};

// helper recursive function
nodePair maxSubset(node* root) {
    
    nodePair p;
    
    // base case
    if(root == NULL) {
        p.include = 0;
        p.exclude = 0;
        return p;
    }
    
    // rec case
    nodePair left = maxSubset(root->left);
    nodePair right = maxSubset(root->right);
    
    int includeSum = root->data + left.exclude + right.exclude;
    int excludeSum = max(left.include, left.exclude) + max(right.include, right.exclude);

    
    p.include = includeSum;
    p.exclude = excludeSum;
    
    return p;
}

int getMaxSubsetSum(node *root) {
    nodePair p = maxSubset(root);
    // cout<<"\np.include = "<<p.include;
    // cout<<"\np.exclude = "<<p.exclude;
    return max(p.include, p.exclude);
}


int main() {

    node *root = buildTree();
    int maxSum = getMaxSubsetSum(root);
    cout<<"\nMAX SUM = "<<maxSum;
	return 0;
}