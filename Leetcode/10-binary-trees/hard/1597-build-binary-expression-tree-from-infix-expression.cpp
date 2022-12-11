/*******************************************************************
Example 1:

 Input: s = "2-3/(5*2)+1"
 Output: [+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]


 Example 2:

 Input: s = "3*4-2*5"
 Output: [-,*,*,3,4,2,5]


 Example 3:

 Input: s = "1+2+3+4+5"
 Output: [+,+,5,+,4,null,null,+,3,null,null,1,2]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<char> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);
    vector<char> level;
        
    while(!q.empty()) {

        TreeNode* curr_node = q.front(); q.pop();
        if(curr_node == NULL) {
            level.push_back('N');
            continue;
        }
        level.push_back(curr_node->val);
        q.push(curr_node->left);
        q.push(curr_node->right);

    }

    return level;
}

class Solution {

    void combine(stack<TreeNode*> &nodeStack, stack<char> &operators) {
        char op = operators.top(); operators.pop();

        // creating new node after combining
        TreeNode* newNode = new TreeNode(op);
        newNode->right = nodeStack.top(); nodeStack.pop();
        newNode->left = nodeStack.top(); nodeStack.pop();

        nodeStack.push(newNode);
    }

public: 
    TreeNode* buildExpressionTree(string &s) {

        stack<TreeNode*> nodeStack;
        stack<char> operators;
        unordered_map<char, int> priority;
        priority['('] = 1;
        priority['+'] = 2;
        priority['-'] = 2;
        priority['*'] = 3;
        priority['/'] = 3;

        for(char ch : s) {

            if(ch == '(') {
                operators.push(ch);
            }

            else if(ch == ')') {
                while(operators.top() != '(') {
                    combine(nodeStack, operators);
                }
                operators.pop();
            }

            else if(isdigit(ch)) {
                TreeNode* newNode = new TreeNode(ch);
                nodeStack.push(newNode);
            }

            // ch is an operator
            else {
                while(!operators.empty() && priority[operators.top()] >= priority[ch]) {
                    combine(nodeStack, operators);
                }
                operators.push(ch);
            }
        }

        while(!operators.empty()) {
            combine(nodeStack, operators);
        }

        return nodeStack.top();
    }
}; 

int main() {

    string s = "1+2+3+4+5"; // "3*4-2*5"; //"2-3/(5*2)+1";
    Solution sol;
    TreeNode* root = sol.buildExpressionTree(s);
    auto res = levelOrder(root);
    for(auto v : res) {
        cout<<v<<" ";
    } 

    return 0;
}