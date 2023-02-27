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


// *************** DISCUSS SOLUTION ***************
class Solution {

    bool nodeExists(TreeNode* root, string &curr, int &node) {
        if(root == NULL) return false;

        if(root->val == node) return true;

        if(root->left && nodeExists(root->left, curr, node)) {
            curr.push_back('L');
            return true;
        }

        else if (root->right && nodeExists(root->right, curr, node)) {
            curr.push_back('R');
            return true;
        }

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
       
        string startString = "";
        nodeExists(root, startString, startValue);
        
        string destString = "";
        nodeExists(root, destString, destValue);

        // actual path is reverse 
        reverse(startString.begin(), startString.end());
        reverse(destString.begin(), destString.end());

        // chuck out common points
        int i = 0;
        int j = 0;
        while(i < startString.length() && j < destString.length()) {
            if(startString[i] != destString[j]) break;
            i++;
            j++; 
        }

        // get their substrings
        startString = startString.substr(i);
        destString = destString.substr(j);

        // replace startString with U onli
        for(int k=0; k<startString.length(); k++) {
            startString[k] = 'U';
        }

        string result = startString + destString;
        
        return result;
    }
};


// *************** MY SOLUTION ***************
class Solution {

    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root == NULL) return NULL;

        if(root->val == p) return root;
        if(root->val == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(!left && !right) return NULL;
        if(!left && right) return right;
        if(left && !right) return left;

        return root;
    }

    bool nodeExists(TreeNode* root, string &curr, int &node) {
        if(root == NULL) return false;

        if(root->val == node) return true;

        if(nodeExists(root->left, curr, node)) {
            curr.push_back('L');
            return true;
        }

        else if (nodeExists(root->right, curr, node)) {
            curr.push_back('R');
            return true;
        }

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);

        string startString = "";
        nodeExists(lca, startString, startValue);
        for(int i=0; i<startString.length(); i++) {
            startString[i] = 'U';
        }
        
        string destString = "";
        nodeExists(lca, destString, destValue);
        reverse(destString.begin(), destString.end());

        string result = startString + destString;

        // cout<<startString<<", "<<destString;
        return result;
           
    }
};