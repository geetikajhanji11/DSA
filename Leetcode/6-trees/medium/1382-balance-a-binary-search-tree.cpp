/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// *********** APPROACH - 1 ***********
// Do inorder traversal of BST O(N), store in vector
// Vector is sorted
// Make a balanced BST from sorted vector

void inorder(TreeNode* root, vector<int> &sortedNodes) {
    if(root == NULL) return;

    inorder(root->left, sortedNodes);
    sortedNodes.push_back(root->val);
    inorder(root->right, sortedNodes);
}

TreeNode* convertArrayToBST(int low, int high, vector<int> &sortedNodes) {
    if(low > high) return NULL;

    int mid = (low + high) / 2;

    TreeNode* curr = new TreeNode(sortedNodes[mid]);
    curr->left = convertArrayToBST(low, mid-1, sortedNodes);
    curr->right = convertArrayToBST(mid+1, high, sortedNodes);

    return curr;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> sortedNodes;
    inorder(root, sortedNodes);
    TreeNode* newRoot = convertArrayToBST(0, sortedNodes.size()-1, sortedNodes);
    return newRoot;
}

// *********** APPROACH - 2 ***********
// Do AVL rotations:
// LL, LR, RR, RL
class Solution {
public:
  TreeNode* balanceBST(TreeNode* root) {
    TreeNode dummy (0, nullptr, root);
    solve(&dummy, dummy.right);
    return dummy.right;
  }
  
private:
  // return { height, balance }
  pair<int, int> solve(TreeNode* root, TreeNode* child) {
    if (!child)
      return { 0, 0 };
    
    auto [ leftHeight, leftBalance ] = solve(child, child->left);
    auto [ rightHeight, rightBalance ] = solve(child, child->right);
    
    int balance = leftHeight - rightHeight;
    
    // left side is heavy
    if (balance > 1) {
        // LR Rotation
        if (leftBalance < 0) { // left->right side is heavy
            rotateLeft(child, child->left);
            return solve(root, rotateRight(root, child));
        } 
        // LL Rotation
        else { // left->left side is heavy
            return solve(root, rotateRight(root, child));
        }
    }
    
    // right side is heavy
    if (balance < -1) {
        // RL Rotation
        if (rightBalance > 0) { // right->left side is heavy
            rotateRight(child, child->right);
            return solve(root, rotateLeft(root, child));
        }   
        // RR Rotation
        else { // right->right side is heavy
            return solve(root, rotateLeft(root, child));
        }  
    }
    
    // if call reached here, tree is currently balanced
    int height = 1 + max(leftHeight, rightHeight);
    return { height, balance };
  }
  
  TreeNode* rotateLeft(TreeNode* node, TreeNode* child) {
    TreeNode* tmp = child->right;
    child->right = tmp->left;
    tmp->left = child;
    
    if (node->left == child)
      node->left = tmp;
    else
      node->right = tmp;
    
    return tmp;
  }
  
  TreeNode* rotateRight(TreeNode* node, TreeNode* child) {
    TreeNode* tmp = child->left;
    child->left = tmp->right;
    tmp->right = child;
    
    if (node->left == child)
      node->left = tmp;
    else
      node->right = tmp;
    
    return tmp;
  }
};

int main() {

    return 0;
}