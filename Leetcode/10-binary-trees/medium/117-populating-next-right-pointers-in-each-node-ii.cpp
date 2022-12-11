/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// class Solution {
// public:
//     Node* connect(Node* root) {
//        if(root == NULL) return NULL;

//        Node* left = root->left;
//        Node* right = root->right;
//        Node* next = root->next;

//        if(left != NULL) {
//             left->next = right;
//             if(next != NULL) {
//                 right->next = next->left;
//             }
//             connect(left);
//             connect(right);
//        }

//        return root;

//     }
// };

// O(1) space, O(N) time
// iterative
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        Node* prevLevel = root;

        while(prevLevel != NULL) {

            Node* currLevel = NULL;

            // find the first ever child of the prev level
            // this child will be start of the curr level
            while(prevLevel != NULL) {

                if(prevLevel->left != NULL) {
                    currLevel = prevLevel->left;
                    break;
                } 
                
                if(prevLevel->right != NULL) {
                    currLevel = prevLevel->right;
                    break;
                }

                prevLevel = prevLevel->next;
            }

            // could not find a child
            // bfs ends and loop terminates
            if(currLevel == NULL) break;
            
            // create dummy node to avoid edge case handling
            Node* dummy = new Node();
            Node* curr = dummy;

            // go through every node in prev level
            while(prevLevel != NULL) {

                // connect the left child, if exists
                if(prevLevel->left != NULL) {
                    curr->next = prevLevel->left;
                    curr = curr->next;
                }

                // connect the right child, if exists
                if(prevLevel->right != NULL) {
                    curr->next = prevLevel->right;
                    curr = curr->next;
                }
            
                // hop on to the next node of the prev level
                prevLevel = prevLevel->next;
            }

            // delete the dummy node to avoid memory leak
            delete dummy;

            // set prevlevel as currlevel for next iteration
            prevLevel = currLevel;
        }

        return root;
    }
};

// generalized solution
// O(N) space and O(N) time
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            Node* head = q.front(); q.pop();
            int size = q.size();

            if(head->left != NULL) q.push(head->left);
            if(head->right != NULL) q.push(head->right);

            while(size != 0) {
                
                Node* curr = q.front(); q.pop();

                head->next = curr;
                head = head->next;

                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);

                size--;
            }


        }

        return root;
    }
};