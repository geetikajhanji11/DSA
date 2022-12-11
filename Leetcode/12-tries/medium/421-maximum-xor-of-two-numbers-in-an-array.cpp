/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* left; // 0
    Node* right; // 1
    Node() {
        this->left = NULL;
        this->right = NULL;
    }
};

class Trie {
    public:

    Node* root;
    Trie() {
        this->root = new Node();
    }

    void insertNumber(int num) {
        Node* curr = root;
        for(int i=31; i>=0; i--) {
            int bit = num>>i & 1;
            if(bit == 0) {
                if(curr->left == NULL) {
                    curr->left = new Node();
                }
                curr = curr->left;
            } else {
                if(curr->right == NULL) {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }

    int getMaxXor(int num) {
        int max_xor = 0;
        Node* curr = root;

        for(int i=31; i>=0; i--) {
            int bit = num>>i & 1;

            // if bit = 1 => GO FOR 0 (possibly)
            if(bit == 1) { 
                // left pointer is not null
                // found a 0
                if(curr->left != NULL) {
                    max_xor += 1<<i;
                    curr = curr->left;
                } else { // found a 1
                    curr = curr->right;
                }   
            }

            // if bit = 0 => GO FOR 1 (possibly)
            else {
                // right pointer is not null
                // found a 1
                if(curr->right != NULL) { 
                    max_xor += 1<<i;
                    curr = curr->right;
                } else { // found a 0
                    curr = curr->left;
                }
            }
        }
        return max_xor;
    }

};

int findMaximumXOR(vector<int>& nums) {
    Trie t;
    int max_xor = 0;
    for(int num : nums) {
        t.insertNumber(num);
        int curr_xor = t.getMaxXor(num);
        max_xor = max(max_xor, curr_xor);
    }       
    return max_xor;
}

int main() {

    return 0;
}