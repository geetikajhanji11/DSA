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

class Node {
public:
    int val;
    int parent;
    int depth;
    Node(int val) {
        this->val = val;
        this->parent = -1;
        this->depth = -1;
    }
};

class Solution {

    void dfs(TreeNode* root, int parent, int depth, Node &node1, Node &node2) {
        if(root == NULL) return;

        if(root->val == node1.val) {
            node1.parent = parent;
            node1.depth = depth;
        }

        if(root->val == node2.val) {
            node2.parent = parent;
            node2.depth = depth;
        }

        dfs(root->left, root->val, depth + 1, node1, node2);
        dfs(root->right, root->val, depth + 1, node1, node2);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;

        Node node1(x);
        Node node2(y);

        dfs(root, root->val, 0, node1, node2);

        return (node1.parent != node2.parent) && (node1.depth == node2.depth);
    }
};