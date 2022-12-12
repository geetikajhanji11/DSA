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

class CBTInserter {
    TreeNode* mainRoot;
    queue<TreeNode*> mainQ;

public:
    CBTInserter(TreeNode* root) {
        mainRoot = root;

        // level order traversal
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);

        // push all the nodes of the last complete level
        // and the nodes of the last level
        while(!q.empty()) {
            int size = q.size();

            // last complete level
            if(size == pow(2, level)) {
                mainQ = q;
            }

            // last level
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front(); q.pop();
                if(curr->left) {
                    mainQ.push(curr->left);
                    q.push(curr->left);
                }
                if(curr->right) {
                    mainQ.push(curr->right);
                    q.push(curr->right);
                }
            }

            level++;
        }

        // remove fully populated nodes
        // i.e. nodes having both children
        while(!mainQ.empty() && mainQ.front()->left != NULL && mainQ.front()->right != NULL) {
            mainQ.pop();
        }

    }
    
    int insert(int val) {
        TreeNode* parent = mainQ.front();
        TreeNode* child = new TreeNode(val);

        // attaching child to left of parent
        if(parent->left == NULL) {
            parent->left = child; 
        } else { // attaching child to right of parent
            parent->right = child;
            mainQ.pop();
        }

        mainQ.push(child);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return mainRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */