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
	int klengthpref(vector<string> words, string str, int k) {
        Trie trie;
        for(string word : words) {
            trie.insert(word);
        }
        string substring = str.substr(0, k);
        return trie.getPrefixCount(substring);
		
	}
};

// *********** WITHOUT USING TRIE ***********
// class Solution {
// public:
// 	int klengthpref(vector<string> words, string str, int k) {

// 		string substring = str.substr(0, k); 
// 		int count = 0; 

//         for(string word : words) {
//             string currSubstring = "";
//             for(int i=0; i<k; i++) {
//                 currSubstring += word[i];
//             }
//             if(currSubstring == substring) {
//                 count++;
//             }
//         }

//         return count;
// 	}
// };

int main() {
	vector<string> words = { "abba", "abbb", "abbc",
					"abbd", "abaa", "abca" };
	string str = "abbg";
    int k = 3;
	Solution ob;
	cout << ob.klengthpref(words, str, k);

	return 0;
}
