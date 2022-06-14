/******************************************************************************

LITTLE CUTE CAT 

Little cute kitten loves to write stories in Github readme document.
One day she is given a list of words, you want to help her to check
if each of these words are present in the readme file.

Sample Input

    document = "little cute cat loves to code in c++, java & python"
    words = ["cute cat", "ttle", "cutest", "cat", "quick", "big"]
    
Sample Output
    YES
    YES
    NO
    YES 
    NO
    NO


*******************************************************************************/

#include <iostream>
#include<vector>
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
};

void search_helper(Trie t, string document, int i, unordered_map<string, bool> &m) {
    
    Node *temp = t.root;
    for(int j=i; j<document.length(); j++) {
        char ch = document[j];
        if(temp->m.count(ch) == 0) {
            return;
        }
        temp = temp->m[ch];
        if(temp->isTerminal) {
            string history = document.substr(i, j-i+1);
            m[history] = true;
        }
    }
    return;
}

void document_search(string document, vector<string> words) {
    
    // create trie of words
    Trie t;
    for(string word : words) {
        t.insert(word);
    }
    
    // searching
    unordered_map<string, bool> m;
    for(int i=0; i<document.length(); i++) {
        search_helper(t, document, i, m);
    }
    
    for(string word : words) {
        cout<<word<<" : ";
        if(m[word]) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}

int main() {
   
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words = {"cute cat", "ttle", "cutest", "cat", "quick", "big"};


    document_search(document, words);

    return 0;
}
