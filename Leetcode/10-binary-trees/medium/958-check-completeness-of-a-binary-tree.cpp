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

// ***************** DISCUSS SOLUTION *****************
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        bool reachedNULL = false;

        // level order traversal
        while(!q.empty()) {

            TreeNode* curr = q.front(); q.pop();
            
            if(curr == NULL) {
                reachedNULL = true;
            }

            else {
                if(reachedNULL) return false;
                q.push(curr->left);
                q.push(curr->right);
            } 
        }
        return true;
    }
};


// ***************** MY SOLUTION *****************
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        // level order traversal
        while(!q.empty()) {

            int size = q.size();
            while(size != 0) {
                
                TreeNode* curr = q.front(); q.pop();

                // right child is NULL but left may or may not be NULL
                if(curr->right == NULL) {

                    // if left child exists, 
                    // and if it has any children,
                    // return false
                    if(curr->left != NULL) {
                        if(curr->left->left != NULL || curr->left->right != NULL) return false;
                    } 

                    // check if all other nodes in current level
                    // also don't have children
                    while(!q.empty()) {
                        if(q.front()->left != NULL || q.front()->right != NULL) return false;
                        q.pop();
                    }
                    return true;
                }
                
                // straightforward
                else if(curr->left == NULL && curr->right != NULL) {
                    return false;
                } 
                
                // normal bfs traversal
                else {
                    q.push(curr->left);
                    q.push(curr->right);
                }

                size--;
            }

        }
        return true;
    }
};