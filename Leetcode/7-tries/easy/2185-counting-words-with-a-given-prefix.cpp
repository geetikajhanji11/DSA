/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** USING TRIE ***********
class Solution {

    class Node {
    public:
        char val;
        unordered_map<char, Node*> children;
        int freq;
        bool isTerminal;
        Node(char ch) {
            this->val = ch;
            this->freq = 0;
            this->isTerminal = false;
        }
    };

    class Trie {
        Node* root;
    public: 

        Trie() {
            this->root = new Node('/');
        }

        void insert(string word) {
            Node* temp = root;
            for(char ch : word) {
                if(temp->children.find(ch) == temp->children.end()) {
                    temp->children[ch] = new Node(ch);
                }
                temp = temp->children[ch];
                temp->freq++;
            }
            temp->isTerminal = true;
        }

        int getPrefixCount(string str) {
            Node* temp = root;
            for(char ch : str) {
                if(temp->children.find(ch) == temp->children.end()) return 0;
                temp = temp->children[ch];
            }
            return temp->freq;
        }
    };

public:
    int prefixCount(vector<string>& words, string pref) {
        Trie trie;
        for(string word : words) {
            trie.insert(word);
        }
        return trie.getPrefixCount(pref);
    }
};

// *********** WITHOUT USING TRIE ***********
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(string word : words) {
            if(word.length() < pref.length()) continue;

            string currPrefix = "";
            for(int i=0; i<pref.length(); i++) {
                currPrefix += word[i];
            }

            if(currPrefix == pref) count++;
        }

        return count;
    }
};

// *********** FOLLOW UP QUESTION ***********
// What if the words are sorted lexicographically?
// Ans => Get the first and last occurence of
// the word having the prefix
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        sort(words.begin(), words.end()); 
        int first = binarySearchFirst(words, pref);
        int last = binarySearchLast(words, pref);
        return first == -1 ? 0 : last - first + 1;
    }

    bool hasPrefix(string word, string pref) {
        if(word.length() < pref.length()) return false;
        for(int i=0; i<pref.length(); i++) {
            if(word[i] != pref[i]) return false;
        }
        return true;
    }
    
    int binarySearchFirst(vector<string>& words, string pref) {
        int low = 0;
        int high = words.size() - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(hasPrefix(words[mid], pref)) {
                idx = mid;
                high = mid - 1;
            } 
            
            else if(words[mid] < pref) {
                low = mid + 1;
            }

            else if(words[mid] > pref) {
                high = mid - 1;
            }

        }
        return idx;
    }
    
    int binarySearchLast(vector<string>& words, string pref) {
        int low = 0;
        int high = words.size() - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(hasPrefix(words[mid], pref)) {
                idx = mid;
                low = mid + 1;
            } 
            
            else if(words[mid] < pref) {
                low = mid + 1;
            }

            else if(words[mid] > pref) {
                high = mid - 1;
            }

        }
        return idx;
    }
};