/*******************************************************************

Design an algorithm to serialize & deserialize a binary tree
Use stringstream to concisely handle negatives, nulls, etc.

Time: O(n) serialize, O(n) deserialize
Space: O(n) serialize, O(n) deserialize

MY CODE EXCEEDS TIME LIMIT

below code is also easy to understand
*********************************

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
    
private:
    
    void encode(TreeNode* root, ostringstream& out) {
        if (root == NULL) {
            out << "N ";
            return;
        }
        
        out << root->val << " ";
        
        encode(root->left, out);
        encode(root->right, out);
    }
    
    TreeNode* decode(istringstream& in) {
        string value = "";
        in >> value;
        
        if (value == "N") {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(value));
        
        root->left = decode(in);
        root->right = decode(in);
        
        return root;
    }
    
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void dfs_encode(TreeNode* curr_node, string &str) {
        if(curr_node == NULL) {
            str += "N,";
            return;
        }
        str += to_string(curr_node->val) + ",";
        dfs_encode(curr_node->left, str);
        dfs_encode(curr_node->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded_string = "";
        dfs_encode(root, encoded_string);
        return encoded_string;
    }

    vector<string> split(string str, char seperator) {  

        char* char_arr = &str[0];
        char *ptr; 
        vector<string> res;

        ptr = strtok(char_arr, ","); 
        while (ptr != NULL)  {  
            string s(ptr);
            res.push_back(s);
            ptr = strtok (NULL, " , ");  
        }  

        return res;
    }  

    TreeNode* dfs_decode(int &i, vector<string> data) {

        if(i >= data.size()) return NULL;
        
        if(data[i] == "N") {
            i = i + 1;
            return NULL;
        }
        
        int num = stoi(data[i]);
        TreeNode* curr = new TreeNode(num);
        i = i + 1;
        curr->left = dfs_decode(i, data);;
        curr->right = dfs_decode(i, data);;

        return curr;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        vector<string> d = split(data, ',');
        d.pop_back();
        return dfs_decode(i, d);
    }
};

int main() {

    return 0;
}