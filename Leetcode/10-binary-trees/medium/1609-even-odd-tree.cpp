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

class Solution {
 
    bool isEven(int &x) {
        return x % 2 == 0;
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int size = q.size();

            int isEvenLevel = isEven(level);
            int prevNum = isEvenLevel ? INT_MIN : INT_MAX;

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front(); q.pop();

                // strictly increasing order
                if(isEvenLevel) {
                    if(isEven(node->val)) return false;
                    if(prevNum >= node->val) return false;
                } 
                
                // strictly decreasing order
                else {
                    if(!isEven(node->val)) return false;
                    if(prevNum <= node->val) return false;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                prevNum = node->val;
            }

            level++;
        }

        return true;
    }
};