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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// *************** DISCUSS SOLUTION ***************
class Solution {

    bool isLinkedListPresent(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root == NULL) return false;
        if(head->val != root->val) return false;
        return isLinkedListPresent(head->next, root->left) || 
            isLinkedListPresent(head->next, root->right);
    }

public:

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root == NULL) return false;
        return isLinkedListPresent(head, root) || 
            isSubPath(head, root->left) || 
            isSubPath(head, root->right);
    }

};

// *************** MY SOLUTION ***************
class Solution {

    void traverse(TreeNode* root, ListNode* head, vector<TreeNode*> &possibleTreeNodes) {
        if(root == NULL) return;
        if(root->val == head->val) {
            possibleTreeNodes.push_back(root);
        }
        traverse(root->left, head, possibleTreeNodes);
        traverse(root->right, head, possibleTreeNodes);
    }

    bool isLinkedListPresent(TreeNode* root, ListNode* head) {
        if(head == NULL) return true;
        if(root == NULL && head != NULL) return false;

        if(root->val != head->val) return false;

        return isLinkedListPresent(root->left, head->next) || 
            isLinkedListPresent(root->right, head->next);
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {

        if(head == NULL) return true;
        if(root == NULL && head != NULL) return false;

        // find target nodes head in the tree
        vector<TreeNode*> possibleTreeNodes;
        traverse(root, head, possibleTreeNodes);

        for(TreeNode* possibleRoot : possibleTreeNodes) {
            if(isLinkedListPresent(possibleRoot, head)) return true;
        }

        return false;
    }
};