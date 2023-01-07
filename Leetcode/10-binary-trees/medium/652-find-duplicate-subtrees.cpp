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

// ******************* DISCUSS SOLUTION *******************
class Solution {

    unordered_map<string, int> tripletToId;
    unordered_map<int, int> idCount;

    int getId(TreeNode* root, vector<TreeNode*> &result) {
        if(root == NULL) return 0;

        int leftSubtreeId = getId(root->left, result);
        int rightSubtreeId = getId(root->right, result);

        string triplet = to_string(leftSubtreeId) + "," + to_string(root->val) + "," + to_string(rightSubtreeId); 

        int id;
        // have never seen this triplet
        if(tripletToId.find(triplet) == tripletToId.end()) {
            id = tripletToId.size() + 1;
            tripletToId[triplet] = id;
        } 
        
        // have seen this triplet before,
        // already seen subtree
        else {
            id = tripletToId[triplet];
        }

        idCount[id]++;
        if(idCount[id] == 2) {
            result.push_back(root);
        }
    
        return id;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;

        getId(root, result);

        return result;
    }
};

// ******************* TLE *******************
class Solution {

    unordered_map<int, vector<TreeNode*>> m;
    unordered_set<TreeNode*> inResult;

    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 != NULL && root2 == NULL) return false;
        if(root1 == NULL && root2 != NULL) return false;

        if(root1->val != root2->val) return false;

        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
    }

    void dfs(TreeNode* root, vector<TreeNode*> &result) {
        if(root == NULL) return;

        bool foundMatch = false;
        if(m.find(root->val) != m.end()) {
            for(TreeNode* node : m[root->val]) {
                if(isSameTree(node, root)) {
                    if(inResult.find(node) == inResult.end()) {
                        result.push_back(node);
                        inResult.insert(node);
                    }
                    foundMatch = true;
                }
            }
        }

        if(!foundMatch) {
            m[root->val].push_back(root);
        }

        dfs(root->left, result);
        dfs(root->right, result);
    }


public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;

        dfs(root, result);

        return result;

    }
};