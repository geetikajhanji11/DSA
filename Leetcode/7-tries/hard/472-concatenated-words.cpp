/*******************************************************************
SIMILAR TO WORD BREAK
*******************************************************************/

#include<iostream>
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
            if(temp->children.find(ch) == temp->children.end()) {
                temp->children[ch] = new_TrieNode;
            } 
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
    }
};

class Solution {
    void dfs(int i, TrieNode* root, int ctr, Trie &t, string &s, unordered_set<string> &result) {

        if(i == s.length()) {
            if(root->isTerminal && ctr >= 1) {
                result.insert(s);
            }
            return;
        }

        if(root->isTerminal) {
            dfs(i, t.root, ctr+1, t, s, result);
        } 

        if(root->children.find(s[i]) != root->children.end()) {
            dfs(i+1, root->children[s[i]], ctr, t, s, result);
        } 
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie t;
        for(string word : words) {
            t.insert(word);
        }

        unordered_set<string> result;
        for(string word : words) {
            dfs(0, t.root, 0, t, word, result);
        }

        vector<string> v(result.begin(), result.end());

        return v;
    }
};