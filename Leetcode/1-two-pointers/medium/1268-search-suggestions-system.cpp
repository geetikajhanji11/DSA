/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ********************* TWO POINTERS *********************
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        int left = 0;
        int right = products.size() - 1;

        vector<vector<string>> result;
        for(int i=0; i<searchWord.length(); i++) {

            while(left <= right && (i >= products[left].length() || products[left][i] != searchWord[i])) left++;
            while(left <= right && (i >= products[right].length() || products[right][i] != searchWord[i])) right--;
        
            vector<string> words;
            int k = left;
            while(words.size() < 3 && k <= right) {
                words.push_back(products[k]);
                k++;
            }
            
            result.push_back(words);

        }

        return result;
    }
};


// ********************* TRIE *********************
// LESS EFFICIENT 
class Solution {
    class TrieNode {
    public:
        char ch;
        unordered_map<char, TrieNode*> children;
        bool isTerminal;
        string word;

        TrieNode(char ch) {
            this->ch = ch;
            this->isTerminal = false;
            this->word = "";
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
            temp->word = word;
        }

        void getWords(TrieNode* root, set<string> &words) {

            if(words.size() == 3) return;
            
            if(root->isTerminal) {
                words.insert(root->word);
                if(words.size() == 3) return;
            }

            for(int i=0; i<26; i++) {
                char ch = 'a' + i;
                if(root->children.find(ch) == root->children.end()) continue; 
                getWords(root->children[ch], words);
            }
        }
        
        vector<vector<string>> findWords(string word) {
            TrieNode* temp = root;

            vector<vector<string>> result;
            for(char ch : word) {

                
                if(temp->children.find(ch) == temp->children.end()) {
                    break;    
                }
                
                temp = temp->children[ch];
                set<string> possibleWords;

                for(int i=0; i<26; i++) {
                    set<string> currWords;
                    getWords(temp, currWords); 
                    
                    // int j = 0;
                    // while(possibleWords.size() < 3 && j < currWords.size()) {
                    //     possibleWords.push_back(currWords[j]);
                    //     j++;
                    // }

                    for(string str : currWords) {
                        possibleWords.insert(str);
                        if(possibleWords.size() == 3) break;
                    }

                    if(possibleWords.size() == 3) break;

                }
                
                vector<string> v(possibleWords.begin(), possibleWords.end());
                result.push_back(v);
                

            }

            return result;
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for(string product : products) {
            t.insert(product);
        }

        vector<vector<string>> result = t.findWords(searchWord);
        return result;
    }
};