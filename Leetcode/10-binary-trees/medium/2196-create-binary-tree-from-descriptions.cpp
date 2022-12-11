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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> count;
        unordered_map<int, TreeNode*> node;

        for(auto desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2];

            if(node.find(parent) == node.end()) {
                TreeNode* parentNode = new TreeNode(parent);
                node[parent] = parentNode;
                count[parent] = 0;
            }

            if(node.find(child) == node.end()) {
                TreeNode* childNode = new TreeNode(child);
                node[child] = childNode;
                count[child] = 0;
            }

            TreeNode* parentNode = node[parent];
            TreeNode* childNode = node[child];

            if(isLeft) parentNode->left = childNode;
            else parentNode->right = childNode;
            count[child]++;
        }

        for(auto it : count) {
            if(it.second == 0) {
                return node[it.first];
            }
        }

        return NULL;
    }
};