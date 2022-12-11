/*******************************************************************
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        def preorder(node, path):
            nonlocal count
            if node:
                # compute occurences of each digit 
                # in the corresponding register
                path = path ^ (1 << node.val)
                # if it's a leaf, check if the path is pseudo-palindromic
                if node.left is None and node.right is None:
                    # check if at most one digit has an odd frequency
                    if path & (path - 1) == 0:
                        count += 1
                else:                    
                    preorder(node.left, path)
                    preorder(node.right, path) 
        
        count = 0
        preorder(root, 0)
        return count
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

// *********** BIT MANIPULATION ***********
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
        if(root == NULL) return 0;

        // take XOR at root->val's bit position
        count ^= 1 << (root->val - 1);

        int left = pseudoPalindromicPaths(root->left, count);
        int right = pseudoPalindromicPaths(root->right, count);
        int res = left + right;

        // count & (count - 1) is 0 if: 
        // count itself is 0 (0 odd bits present)
        // there is only 1 set bit (1 odd bit present)
        if(root->left == root->right && (count & (count - 1)) == 0) {
            res++;
        }
        
        return res;
    }
};

// *********** OPTIMIZED ***********
class Solution {

    void dfs(TreeNode* root, vector<int> &freq, int oddCount, int &count) {
        if(root == NULL) return;

        if(freq[root->val] % 2 == 0) oddCount++;
        else oddCount--;

        // incrementing
        freq[root->val]++;

        if(root->left == NULL && root->right == NULL) {
            if(oddCount == 0 || oddCount == 1) {
                count++;
            }
        }
        
        dfs(root->left, freq, oddCount, count);
        dfs(root->right, freq, oddCount, count);

        // backtracking
        freq[root->val]--;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> freq(10, 0);
        dfs(root, freq, 0, count);
        return count;
    }
};

// *********** INTUITIVE (TLE) ***********
class Solution {

    bool isPseudoPalindromic(unordered_map<int, int> freq) {
        int oddFreqCount = 0;
        for(auto kv : freq) {
            if(kv.second % 2 != 0) oddFreqCount++;
        } 
        return oddFreqCount == 0 || oddFreqCount == 1;
    }

    void dfs(TreeNode* root, unordered_map<int, int> freq, int &count) {
        if(root == NULL) return;

        freq[root->val]++;
        
        if(root->left == NULL && root->right == NULL) {
            if(isPseudoPalindromic(freq)) {
                count++;
            }
        }
        
        dfs(root->left, freq, count);
        dfs(root->right, freq, count);

    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        dfs(root, {}, count);
        return count;
    }
};