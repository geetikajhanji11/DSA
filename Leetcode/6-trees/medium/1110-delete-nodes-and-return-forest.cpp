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

    void findParent(TreeNode* root, unordered_map<int, int> &parent, unordered_map<int, TreeNode*> &node) {
        if(root == NULL) return;

        node[root->val] = root;

        if(root->left != NULL) parent[root->left->val] = root->val;
        if(root->right != NULL) parent[root->right->val] = root->val;

        findParent(root->left, parent, node);
        findParent(root->right, parent, node);
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, int> parent; // -1 means current node is root node
        unordered_map<int, TreeNode*> node; // distinct value of node => TreeNode*

        parent[root->val] = -1;
        findParent(root, parent, node);

        for(int val : to_delete) {
            TreeNode* nodeToDelete = node[val];

            // left child of nodeToDelete
            if(nodeToDelete->left != NULL) {
                parent[nodeToDelete->left->val] = -1;
                nodeToDelete->left = NULL;
            }

            // right child of nodeToDelete
            if(nodeToDelete->right != NULL) {
                parent[nodeToDelete->right->val] = -1;
                nodeToDelete->right = NULL;
            }

            // parent of nodeToDelete
            if(parent[val] != -1) {
                bool isLeftChild = false;
                if(node[parent[val]]->left) {
                    isLeftChild = node[parent[val]]->left->val == val;
                }

                if(isLeftChild) {
                    node[parent[val]]->left = NULL;
                } else {
                    node[parent[val]]->right = NULL;
                }
            }

            // remove from map
            // deallocate used memory
            node[val] = NULL;
            delete nodeToDelete;
        }

        // find all nodes who have parent as -1
        // this means that they are root node of their subtree
        vector<TreeNode*> result;
        for(auto kv : parent) {
            int root = kv.first;
            int parentOfRoot = kv.second;
            if(parentOfRoot == -1 && node[root] != NULL) {
                result.push_back(node[root]);
            }
        }

        return result;

    }
};