/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

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

    void dfs(int i, string curr, TrieNode* root, Trie &t, string &s, vector<string> &result) {
        
        // reached the end of the input string
        // if the root is also the end of a word,
        // push into result
        if(i == s.length() && root->isTerminal) {
            result.push_back(curr);
            return;
        }

        // if previous character denotes the end of 
        // a word, add a " " to curr string to denote 
        // end of the word, next dfs call should start
        // from current character and root should now
        // be the actual root of the trie (Search from beg)
        if(root->isTerminal) {
            dfs(i, curr + " ", t.root, t, s, result);
        }

        // current word exists in the children map
        // of the current node
        if(root->children.find(s[i]) != root->children.end()) {
            curr += s[i];
            dfs(i+1, curr, root->children[s[i]], t, s, result);
        } 
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        unordered_set<string> words;
        for(string word : wordDict) {
            t.insert(word);
        }

        vector<string> result;
        dfs(0, "", t.root, t, s, result);
        return result;
    }
};