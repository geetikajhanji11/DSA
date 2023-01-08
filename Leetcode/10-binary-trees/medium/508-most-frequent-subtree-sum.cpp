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

    int sum(TreeNode* root, unordered_map<int, int> &freq, int &highestFreq, vector<int> &result) {
        if(root == NULL) return 0;

        int leftSum = sum(root->left, freq, highestFreq, result);
        int rightSum = sum(root->right, freq, highestFreq, result);

        int totalSum = leftSum + root->val + rightSum;

        freq[totalSum]++;

        if(freq[totalSum] > highestFreq) {
            highestFreq = freq[totalSum];
            result.clear();
        }

        if(freq[totalSum] == highestFreq) {
            result.push_back(totalSum);
        }

        return totalSum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq; // sum => frequency of sum
        int highestFreq = 0;
        vector<int> result;

        sum(root, freq, highestFreq, result);

        return result;

    }
};