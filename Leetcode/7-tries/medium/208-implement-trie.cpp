#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char ch;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char ch) {
        this->ch = ch;
        this->isTerminal = false;
    } 
};

class Trie {
public:
    TrieNode *root;
    
    Trie() {
        this->root = new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char ch : word) {
            TrieNode* new_TrieNode = new TrieNode(ch);
            // if TrieNode is not currently in the root TrieNode
            if(temp->children.find(ch) == temp->children.end()) {
                temp->children[ch] = new_TrieNode;
            } 
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char ch : word) {
            if(temp->children.find(ch) == temp->children.end()) return false;
            temp = temp->children[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char ch : prefix) {
            if(temp->children.find(ch) == temp->children.end()) return false;
            temp = temp->children[ch];
        }
        return true;
    }
};

int main() {

    return 0;
}