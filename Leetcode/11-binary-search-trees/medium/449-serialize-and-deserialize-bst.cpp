/*******************************************************************
1008 SIMILAR
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

class Codec {

    void preorderEncode(TreeNode* root, string &result) {
        if(root == NULL) {
            result += "N,";
            return;
        }

        result += (to_string(root->val) + ",");
        preorderEncode(root->left, result);
        preorderEncode(root->right, result);
    }

    TreeNode* preorderDecode(int &i, string result) {
        
        if(i == result.length()) return NULL;

        if(result[i] == 'N') {
            i += 2; // for N and ,
            return NULL;
        }

        string valStr = "";
        while(i < result.length() && isdigit(result[i])) {
            valStr += result[i];
            i++;
        }
        i++; // for ,

        int val = stoi(valStr);

        TreeNode* root = new TreeNode(val);
        root->left = preorderDecode(i, result);
        root->right = preorderDecode(i, result);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        preorderEncode(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return preorderDecode(i, data);
    }
};
