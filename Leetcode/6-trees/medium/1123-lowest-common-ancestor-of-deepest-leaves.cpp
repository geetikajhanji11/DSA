/*******************************************************************
SAME AS 1123. Lowest Common Ancestor of Deepest Leaves
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

// ************* DISCUSS SOLUTION (1 PASS) *************
// TIME => O(N)
// SPACE => O(H)
class Solution {

    // int => int height measured from the bottom of the tree
    // TreeNode* => root of the smallest subtree containing the deepest nodes
    pair<int, TreeNode*> getHeightAndSubtree(TreeNode* root) {
        if(root == NULL) return {0, NULL};

        auto left = getHeightAndSubtree(root->left);
        int leftHeight = left.first;
        TreeNode* leftSubtree = left.second;

        auto right = getHeightAndSubtree(root->right);
        int rightHeight = right.first;
        TreeNode* rightSubtreee = right.second;

        // deepest subtree lies left
        if(leftHeight > rightHeight) {
            return {leftHeight + 1, leftSubtree};
        } 

        // deepest subtree lies right
        else if(rightHeight > leftHeight) {
            return {rightHeight + 1, rightSubtreee};
        }

        // both heights are same
        // root is the deepest subtree
        return {leftHeight + 1, root};
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto p = getHeightAndSubtree(root);
        return p.second; 
    }
};

// ************* MY SOLUTION *************
// TIME => O(N)
// SPACE => O(N)
class Solution {

    // returns maximum depth of the tree
    int maxDepth(TreeNode* root) { 
        if(root == NULL) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int maximumDepth = max(leftDepth, rightDepth);
        return maximumDepth + 1;
    }

    // populate the "deepestNodes" and "parent" data structures
    void dfs(TreeNode* root, int depth, int &maximumDepth, unordered_set<TreeNode*> &deepestNodes, unordered_map<TreeNode*, TreeNode*> &parent) {
        if(root == NULL) return;
        
        if(depth == maximumDepth) deepestNodes.insert(root);
        
        if(root->left != NULL) parent[root->left] = root;
        if(root->right != NULL) parent[root->right] = root;

        dfs(root->left, depth + 1, maximumDepth, deepestNodes, parent);
        dfs(root->right, depth + 1, maximumDepth, deepestNodes, parent);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maximumDepth = maxDepth(root);

        unordered_set<TreeNode*> deepestNodes;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = root;
        dfs(root, 1, maximumDepth, deepestNodes, parent);

        while(deepestNodes.size() > 1) {
            unordered_set<TreeNode*> temp;
            for(TreeNode* node : deepestNodes) {
                temp.insert(parent[node]);
            }
            deepestNodes = temp;
        }

        return *deepestNodes.begin();
    }
};