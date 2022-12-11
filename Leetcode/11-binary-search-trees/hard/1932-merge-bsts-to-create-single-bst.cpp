/*******************************************************************
The most important thing to understand is the fact that the 
final root node will be the one which is not found in any trees leaves. 

After figuring this out, we just need to recursively merge the dependecies, 
and finally check if everything has been merged and if the resuting tree 
is a BST or not.
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

    // to check if the final constructed BST is valid or not
    // typical reusable algorithm
    bool isValidBST(TreeNode* root, int leftRange, int rightRange) {
        if(root == NULL) return true;

        bool rootIsValid = leftRange < root->val && root->val < rightRange;
        bool leftIsValid = isValidBST(root->left, leftRange, root->val);
        bool rightIsValid = isValidBST(root->right, root->val, rightRange);

        return rootIsValid && leftIsValid && rightIsValid;
    }

    // merge bsts
    TreeNode* mergeBSTs(TreeNode* root, unordered_map<int, TreeNode*> &rootMap) {
        if(root == NULL) return NULL;

        // if there exists a bst of root value as "root->val" in the map
        // make it the root and erase it from map
        if(rootMap.find(root->val) != rootMap.end()) {
            int rootVal = root->val;
            root = rootMap[rootVal];
            rootMap.erase(rootVal); 
        }

        root->left = mergeBSTs(root->left, rootMap);
        root->right = mergeBSTs(root->right, rootMap);

        return root;
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        if(trees.size() == 0) return NULL;

        unordered_map<int, TreeNode*> rootMap;
        unordered_set<int> leaves;

        // map all root values to root nodes
        for(auto root : trees) {
            rootMap[root->val] = root;
            if(root->left != NULL) leaves.insert(root->left->val);
            if(root->right != NULL) leaves.insert(root->right->val);
        }

        // the main root of the bst is the node
        // which is not any other bst's leaf node
        TreeNode* mainRoot = NULL;
        for(auto root : trees) {
            if(leaves.find(root->val) == leaves.end()) {
                mainRoot = root;
                break;
            }
        }

        // merge all nodes
        mergeBSTs(mainRoot, rootMap);

        // if the final bst is invalid
        // or all the bsts were not used in making final bst
        // return null
        if(!isValidBST(mainRoot, INT_MIN, INT_MAX)) return NULL;
        if(rootMap.size() != 0) return NULL;
        
        // successfully creasted a valid final bst
        return mainRoot;
    }
};