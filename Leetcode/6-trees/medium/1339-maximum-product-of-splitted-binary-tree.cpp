/*******************************************************************
=> Take entire sum of the tree as "totalTreeSum"
=> "subtreeSum" make every node of tree denote the sum of the subtree down below it
=> product = subtreeSum * (totalTreeSum - subtreeSum)

LC Example - 1

    21
   /   \
 11      9 
 / \    /
4   5   6
totalTreeSum = 21
-------------------- [1]
    21
   /   
 11      9 
 / \    /
4   5   6
product = 9 * (21 - 9) = 108
-------------------- [2]
    21
   /   \
 11      9 
 / \    
4   5   6
product = 6 * (21 - 6) = 90
-------------------- [3]
    21
       \
 11      9 
 / \    /
4   5   6
product = 11 * (21 - 11) = 110
-------------------- [4]
    21
   /   \
 11      9 
   \    /
4   5   6
product = 4 * (21 - 4) = 68
-------------------- [5]
    21
   /   \
 11      9 
 /      /
4   5   6
product = 5 * (21 - 5) = 80
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

// ************* MY SOLUTION *************
// See this for logic
// (MOD ERROR, OTHER THAN THAT WORKS FINE)
class Solution {

    int calculateSubtreeSum(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSum = calculateSubtreeSum(root->left);
        int rightSum = calculateSubtreeSum(root->right);

        root->val += (leftSum + rightSum);

        return root->val;
    }

    void traverse(TreeNode* root, int &totalTreeSum, int &maxProduct) {
        if(root == NULL) return;

        int subtreeSum1 = root->val;
        int subtreeSum2 = totalTreeSum - root->val;
        int currProduct = subtreeSum1 * subtreeSum2;

        maxProduct = max(maxProduct, currProduct);

        traverse(root->left, totalTreeSum, maxProduct);
        traverse(root->right, totalTreeSum, maxProduct);
    }

public:
    int maxProduct(TreeNode* root) {

        int totalTreeSum = calculateSubtreeSum(root);
        int maxProduct = INT_MIN;

        traverse(root, totalTreeSum, maxProduct);

        return maxProduct;
    }
};

// passed on LC
class Solution {
public:
    long long ans = 0, totalSum = 0;
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root); // Firstly, get total sum of all nodes in the Binary Tree
        dfs(root); // Then dfs in post order to calculate sum of each subtree and its complement
        return ans % int(1e9+7);
    }
    
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
};