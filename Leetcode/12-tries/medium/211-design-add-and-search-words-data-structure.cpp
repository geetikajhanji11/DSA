#include<bits/stdc++.h>
using namespace std;

// O(N) in worst case for find method in map
// that is why Leetcode does not accept this
// try with array

// class TrieNode {
// public:
//     char ch;
//     unordered_map<char, TrieNode*> children;
//     bool isTerminal;

//     TrieNode(char ch) {
//         this->ch = ch;
//         this->isTerminal = false;
//     } 
// };

// class WordDictionary {
// public:

//     TrieNode* root;
//     WordDictionary() {
//         this->root = new TrieNode('\0');
//     }
    
//     void addWord(string word) {
//         TrieNode* curr_node = root;
//         for(char ch : word) {
//             TrieNode* new_node = new TrieNode(ch);
//             if(curr_node->children.find(ch) == curr_node->children.end()) {
//                 curr_node->children[ch] = new_node;
//             }
//             curr_node = curr_node->children[ch];
//         }
//         curr_node->isTerminal = true;
//     }
    
//     bool search(string word) {
//         return dfs(0, word, root);
//     }

//     bool dfs(int i, string word, TrieNode* root) {
        
//         // base cases
//         if(i == word.size()) return root->isTerminal;

//         // rec case
//         char ch = word[i];

//         if(ch != '.') {
//             if(root->children.find(ch) != root->children.end()) { 
//                 return dfs(i+1, word, root->children[ch]);
//             }
//             else return false;
//         } 
        
//         else {
//             for(auto it=root->children.begin(); it!=root->children.end(); it++) {
//                 if(dfs(i+1, word, it->second)) return true;
//             }
//         }

//         return false;

//     }
// };


class TrieNode {
public:
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        return searchInNode(word, 0, node);
    }

private:
    TrieNode* root;
    
    bool searchInNode(string& word, int i, TrieNode* node) {

        if (node == NULL) return false;
        if (i == word.size()) return node->isTerminal;
        
        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->children[word[i] - 'a']);
        }

        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, node->children[j])) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {

    return 0;
}