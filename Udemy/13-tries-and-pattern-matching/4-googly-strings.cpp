/******************************************************************************

GOOGLY STRINGS

A string is said to be Googly if it is exactly made up of at least
two instances of other string in the input list of strings.

In order for a string to be gtoogly, just containing two instances of 
other strings isn't sufficient, the string must be exactly made up of
those strings. For example, in the list ["a", "b", "abc"], the string
"abc" isn't googly, even though it contains "a" and "b", but "c" isn't
a string in the list.

Note thqat the strings can be repeated to form a special string; for 
example in the list ["a", "aaa"], the string "aaa" is a Googly string
because it is made up of three repeated isntances of "a"

Sample Input:
    {"goo", "gle", "google", "le", "googly", "ly", "g", "googoole"};


Sample Output:
    gle
    google
    googly
    googoole

// --------- PRATEEK SOLUTION -------------
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

// Trie class
class Trie {
    Node *root;
    
    public: 
    
    // constructor
    Trie() {
        root = new Node('\0');
    }
    
    // gets the root of the Trie
    Node *getRoot() {
        return root;
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
        return;
    }
};

// recursive function to check if the string
// is made up of at least 2 other strings or not
bool isSpecial(Trie t, Node *root, string word, int i, int count) {
    
    // base case
    if(i == word.length()) {
        return (root->isTerminal && count + 1 >= 2);
    }
    
    // recursive case
    char current_ch = word[i];
    
    if(root->m.count(current_ch) == 0) {
        return false;
    }
    root = root->m[current_ch];
    
    if(root->isTerminal) {
        bool isRemainingSpecial = isSpecial(t, t.getRoot(), word, i+1, count+1);
        if(isRemainingSpecial) return true;
    }
    
    return isSpecial(t, root, word, i+1, count);
}


vector<string> googlyStrings(vector<string> input) {
    Trie t;
    
    // creating the prefix trie
    for(string word : input) {
        t.insert(word);
    }

    // finding if each word is special or not
    // if it is special, isnert in output vector
    vector<string> output;
    
    for(string word : input) {
        Node *root = t.getRoot();
        int count = 0;
        int i = 0;
        if(isSpecial(t, root, word, i, count)) {
            output.push_back(word);    
        }
    }
    
    return output;
}
*******************************************************************************/

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// **************************************************
// MORE READABLE SOLUTION
// **************************************************

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

// Trie class
class Trie {
    Node *root;
    
    public: 
    
    // constructor
    Trie() {
        root = new Node('\0');
    }
    
    // gets the root of the Trie
    Node *getRoot() {
        return root;
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
        return;
    }
};

bool is_googly(int i, string word, Node* root, Trie t, int count) {
    
    if(i == word.length()) {
        return root->isTerminal && count + 1 >= 2;
    } 

    if(root->m.count(word[i]) == 0) return false;
    root = root->m[word[i]];
    
    if(root->isTerminal) {
        if(is_googly(i+1, word, t.getRoot(), t, count+1)) return true;
    }
    
    return is_googly(i+1, word, root, t, count);
}

vector<string> googlyStrings(vector<string> input) {
    Trie t;
    for(string str : input) {
        t.insert(str);
    }

    vector<string> result;
    for(string str : input) {
        if(is_googly(0, str, t.getRoot(), t, 0)) {
            result.push_back(str);
        }
    }

    return result;
}

int main() {
    
    vector<string> words = {"goo", "gle", "google", "le", "googly", "ly", "g", "googoole"};
    vector<string> output = googlyStrings(words);
    
    for(string word : output) {
        cout<<word<<endl;
    }

    return 0;
}
