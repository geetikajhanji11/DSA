/*******************************************************************
0: [2, 4]
1: []
2: [3, 1]
3: []
4: []
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** MY SOLUTION **************
class Solution {

    int calculateSize(int i, vector<vector<int>> &children, vector<int> &size) {

        if(size[i] != -1) return size[i];

        int nodes = 1; // including current node
        for(int child : children[i]) {
            nodes += calculateSize(child, children, size);
        }

        size[i] = nodes;
        return size[i];
    }


public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();

        // creating a children array for every node
        vector<vector<int>> children(n);
        for(int node=1; node<n; node++) {
            int parent = parents[node];
            children[parent].push_back(node);
        }

        // calculating subtree size for every node
        vector<int> size(n, -1);
        calculateSize(0, children, size);

        // calculating score for every node 
        // "root" if it is removed
        long long highestScore = INT_MIN;
        int highestScoreCount = 0;
        for(int root=0; root<n; root++) {
            
            long long score = 1;
            for(int child : children[root]) {
                score *= size[child];
            }
            if(parents[root] != -1) {
                score *= (n - size[root]);
            }

            // comparing with highestScore
            if(score == highestScore) {
                highestScoreCount++;
            }

            if(score > highestScore) {
                highestScore = score;
                highestScoreCount = 1;
            }

        }

        return highestScoreCount;
    }
};

// ************** OTHER SOL USING TREENODE* **************
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    int calculateSize(TreeNode* root, vector<int> &size) {
        if(root == NULL) return 0;

        int leftSize = calculateSize(root->left, size);
        int rightSize = calculateSize(root->right, size);

        size[root->val] = leftSize + 1 + rightSize;

        return size[root->val];
    }

    void dfs(TreeNode* root, vector<int> &parents, vector<int> &size, int &totalSize, long long &highestScore, int highestScoreCount) {
        if(root == NULL) return;

        long long score = 1;
        if(root->left != NULL) score *= size[root->left->val];
        if(root->right != NULL) score *= size[root->right->val];
        if(parents[root->val] != -1) score *= (totalSize - size[root->val]);

        if(score == highestScore) {
            highestScoreCount++;
        }

        if(score > highestScoreCount) {
            highestScore = score;
            highestScoreCount = 1;
        }
    }

public:
    int countHighestScoreNodes(TreeNode* root, vector<int>& parents) {
        vector<int> size(parents.size(), 0);
        int totalSize = calculateSize(root, size);
        long long highestScore = INT_MIN;
        int highestScoreCount = 0;
        dfs(root, parents, size, totalSize, highestScore, highestScoreCount);
        return highestScoreCount;
    }
};