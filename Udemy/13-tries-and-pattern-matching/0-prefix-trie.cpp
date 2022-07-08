/******************************************************************************

TRIES

Given a list of strings and q queries, each query containing
a word, you have to tell whether the word is contained in the 
list or not

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

class Trie {
    
    public:
    Node *root;
    
    Trie() {
        root = new Node('\0');
    }
    
    // insert a new word
    void insert(string word) {
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
    
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;
    for(auto word : words) {
        t.insert(word);
    }
    
    int q;
    cin>>q;
    
    string search_word;
    while(q--) {
        cin>>search_word;
        if(t.search(search_word)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
