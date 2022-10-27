/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// **************** DISCUSS SOLUTION **************** 
class TrieNode {
public:
    int idx;
    vector<int> indices;
    TrieNode* children[26];
    TrieNode() : idx(-1) {
        memset(children, NULL, sizeof(children));
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            add(words[i], i);
        }
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            search(words[i], i, pairs);
        }
        return pairs;
    }
private:
    TrieNode* root = new TrieNode();
    
    void add(string word, int i) {
        TrieNode* node = root;
        for (int j = word.size() - 1; j >= 0; j--) {
            if (isPalindrome(word, 0, j)) {
                node -> indices.push_back(i);
            }
            if (!node -> children[word[j] - 'a']) {
                node -> children[word[j] - 'a'] = new TrieNode();
            }
            node = node -> children[word[j] - 'a'];
        }
        node -> idx = i;
        node -> indices.push_back(i);
    }
    
    void search(string word, int i, vector<vector<int>>& pairs) {
        TrieNode* node = root;
        int n = word.size();
        for (int j = 0; j < n && node; j++) {
            if (node -> idx >= 0 && node -> idx != i && isPalindrome(word, j, n - 1)) {
                pairs.push_back({i, node -> idx});
            }
            node = node -> children[word[j] - 'a'];
        }
        if (node) {
            for (int idx : node -> indices) {
                if (i != idx) {
                    pairs.push_back({i, idx});
                }
            }
        }
    }
    
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};


// *********************** MY SOLUTION ***********************

bool isPalindrome(string &s) {
    
    int i = 0;
    int j = s.length() - 1;
    
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

class Node {
public:
    char ch;
    unordered_map<char, Node*> children;
    int index; // also indicates whether it is terminal or not (index != -1 => terminal)

    Node(char ch) {
        this->ch = ch;
        this->index = -1;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        this->root = new Node('\0');
    }

    // add word in reverse order
    void addWord(string word, int index) {
        Node* temp = root;
        for(int i=word.length()-1; i>=0; i--) {
            char ch = word[i];
            if(temp->children.find(ch) == temp->children.end()) {
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->index = index;
    }

    void checkOtherPalindromes(string curr, Node* root, vector<int> &indexes) {

        if(!isPalindrome(curr)) return;

        if(curr != "" && root->index != -1) {
            indexes.push_back(root->index);
        }

        for(auto kv : root->children) {
            char ch = kv.first;
            Node* nextNode = kv.second;
            checkOtherPalindromes(curr + ch, nextNode, indexes);
        }
    }

    vector<int> searchPalindrome(string word, int i) {
        vector<int> indexes;

        Node* temp = root;

        for(char ch : word) {
            if(temp->children.find(ch) == temp->children.end()) return {};
            temp = temp->children[ch];
        }
        
        if(temp->index != -1 && temp->index != i) {
            indexes.push_back(temp->index);
        }

        // recursive to find other strings
        string curr = "";
        checkOtherPalindromes(curr, temp, indexes);

        return indexes;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        Trie t;

        int emptyIdx = -1;
        vector<int> paliIdx;
        
        for(int i=0; i<words.size(); i++) {
            t.addWord(words[i], i);
            if(words[i] == "") emptyIdx = i;
            if(isPalindrome(words[i])) paliIdx.push_back(i);
        }

        vector<vector<int>> result;
        
        if(emptyIdx != -1) {
            for(int j : paliIdx) {
                if(j == emptyIdx) continue;
                result.push_back({emptyIdx, j});
                result.push_back({j, emptyIdx});
            }
        }
        
        for(int i=0; i<words.size(); i++) {

            if(words[i] == "") {
                continue;
            } 
            
            vector<int> indexes = t.searchPalindrome(words[i], i);
            for(int j : indexes) {
                result.push_back({i, j});
            }
            
            
        }
        
        

        return result;
    }
};