/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** BETTER SOLUTION  ***************
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i=0; i<strs[0].length(); i++) {
            char ch = strs[0][i];
            for(int j=0; j<strs.size(); j++) {
                if(strs[j][i] != ch) return prefix;
            }
            prefix += ch;
        }
        return prefix;
    } 
};

// *************** TRIE SOLUTION  ***************
// USES EXTRA SPACE
class Node {
    public:
    char ch;
    unordered_map<char, Node*> children;
    bool isTerminal;

    Node(char ch) {
        this->ch = ch;
        this->isTerminal = false; 
    }
};

class Trie {
    public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* curr = root;
        for(char ch : word) {
            if(curr->children.count(ch) == 0) {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->isTerminal = true;
    }

    string getCommonPrefix() {
        string result = "";
        Node* curr = root;
        while(curr->children.size() == 1) {
            if(curr->isTerminal) break;
            result += curr->children.begin()->first;
            curr = curr->children.begin()->second;
        }
        return result;
    }
};

string longestCommonPrefix(vector<string>& strs) {
    Trie t;
    for(string str : strs) {
        if(str.length() == 0) return "";
        t.insert(str);
    }
    return t.getCommonPrefix();
}

int main() {

    return 0;
}