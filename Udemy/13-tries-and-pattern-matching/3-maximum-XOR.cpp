/******************************************************************************

BIGGEST XOR

Given an array, find the maximum XOR that you can form by picking
two numbers from the array

Sample Input
    Input = {3, 10, 5, 8, 2, 25}
    
Sample Output
    Output = 28 (5 XOR 25)


*******************************************************************************/

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    
    Node *left; // 0
    Node *right; // 1 
    
    // constructor
    Node() {
        left = NULL;
        right = NULL;
    }
};

class Trie {
    
    public:
    Node *root;
    
    Trie() {
        root = new Node();
    }
    
    // insert bits of that number in the trie
    void insert(int n) {
        
        Node *curr_node = root;
        for(int i=31; i>=0; i--) {
            // extracting the MSB of the 32-bit number
            int bit = (n>>i) & 1;
            Node *new_bit = new Node();
            
            // if the current bit is 0
            if(bit == 0) {
                // if 0 is not in the prefix
                if(curr_node->left == NULL) {
                    curr_node->left = new_bit;
                }
                
                // 0 bit prefix is already in trie,
                // go down that path
                curr_node = curr_node->left;
            } 
            
            // else if the current bit is 1
            else {
                // if 1 is not in the prefix
                if(curr_node->right == NULL) {
                    curr_node->right = new_bit;
                }
                // 1 bit prefix is already in trie,
                // go down that path
                curr_node = curr_node->right;
            }
        }
    }
};

int maximumXOR_helper(int value, Trie t) {
    int current_ans = 0;
    Node *curr_node = t.root;
    
    // O(32) => constant loop
    for(int j=31; j>=0; j--) {
        int bit = (value>>j) & 1;
        
        // if current bit is 0
        if(bit == 0) {
            // find 1 (opposite)
            if(curr_node->right != NULL) {
                curr_node = curr_node->right;
                current_ans += (1<<j);
            } else {
                curr_node = curr_node->left;
            }
        }
        
        // if current bit is 1
        if(bit == 1) {
            // find 0 (opposite)
            if(curr_node->left != NULL) {
                curr_node = curr_node->left;
                current_ans += (1<<j);
            } else {
                curr_node = curr_node->right;
            }
        }
    }
    return current_ans;
}

int maximumXOR(vector<int> arr) {
    
    int n = arr.size();
    
    Trie t;
    int max_xor = 0;
    
    // getting maximum xor at every step
    // O(n)
    for(int i=0; i<n; i++) {
        int value = arr[i];
        t.insert(value);
        int current_xor = maximumXOR_helper(value, t);
        max_xor = max(max_xor, current_xor);
    }
    
    return max_xor;
    
}


int main() {
   
    vector<int> arr = {3, 10, 5, 25, 9, 2}; //{3, 10, 5, 8, 2, 25};
    
    cout<<maximumXOR(arr);
    
    return 0;
}
