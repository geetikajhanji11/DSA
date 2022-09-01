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

// ******************** BETTER SOLUTION ********************
// PARTIAL INORDER TRAVERSAL 
// next() and hasNext() = O(1) Time
// Overall Space = O(h)
class BSTIterator {

    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while(temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top(); s.pop();

        TreeNode* temp = top->right;
        while(temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }

        return top->val;
    }
    
    bool hasNext() {
        if(s.empty()) return false;
        return true;
    }
};

// ******************** MY INITIAL SOLUTION ********************
// next() and hasNext() = O(1) Time
// Overall Space = O(n)
class BSTIterator {

    TreeNode* curr;
    unordered_map<TreeNode*, TreeNode*> nextMap;

    void inorder(TreeNode* root, TreeNode* &prev) {
        if(root == NULL) return;

        inorder(root->left, prev);

        nextMap[prev] = root;
        prev = root;

        inorder(root->right, prev);
    }

public:
    BSTIterator(TreeNode* root) {
        TreeNode* prev = NULL;
        inorder(root, prev);
        nextMap[prev] = NULL;
        curr = NULL;
    }
    
    int next() {
        curr = nextMap[curr];
        return curr->val;
    }
    
    bool hasNext() {
        if(nextMap[curr] == NULL) return false;
        return true;
    }
};