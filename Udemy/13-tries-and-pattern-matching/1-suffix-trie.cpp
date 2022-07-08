/******************************************************************************

SUFFIX TREE

*******************************************************************************/

#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    
    // constructor
    Node(char d) {
        data = d;
        isTerminal = false;
    }
};

class SuffixTrie {
    
    public:
    Node *root;
    
    SuffixTrie() {
        root = new Node('\0');
    }
    
    // insert a new word
    void insert_helper(string word) {
        Node *curr_node = root;
        
        for(char letter : word) {
            // map does not contain the letter
            if(curr_node->m.count(letter) == 0) {
                Node *n = new Node(letter);
                curr_node->m[letter] = n;
            }
            
            // go to next node
            curr_node = curr_node->m[letter];
        }
        curr_node->isTerminal = true;
    }
    
    void insert(string word) {
        // pick all substrings from (i to endofstring) 
        for(int i=0; i<word.length(); i++) {
            insert_helper(word.substr(i));
        }
    }
    
    // search the word in a trie
    bool search(string word) {
        Node *curr_node = root;
        
        for(char letter : word) {
            
            // map does not contain letter
            // return false
            if(curr_node->m.count(letter) == 0) return false;
            
            // go to next letter
            curr_node = curr_node->m[letter];
        }
        
        return curr_node->isTerminal;
    }
    
};

int main() {
    
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};
    SuffixTrie t;
    
    t.insert(input);
    
    
    for(string search_word : suffixes) {
        if(t.search(search_word)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
