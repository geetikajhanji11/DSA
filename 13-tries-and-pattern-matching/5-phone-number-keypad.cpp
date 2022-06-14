/******************************************************************************

PHONE NUMBER SEARCH

As we can see every digit is associated with some letters, for example, 
2 is mapped with (a,b,c). This allowes certain phone numbers to be mapped 
with actual words. 
For example - the phone number "666" can be written as "mom" or "moo". 
Similarly, "7728335" can be written as "prateek" or some other string 
as well. Hence, a given phone number can represent multiple possible strings.

You are given a phone number (as a string input) and a non-empty list of 
words. Write a function that returns the list of words that can be found 
in the phone number. The final list can contain words in any order. 
(Yes, we will use sorting at the backend to compare your result with ours)


Sample Input:
    phone_number = "7728335"
    words = {"prat", "prateek", "codingminutes", "code", "prat335", "teek"}

Sample Output:
    "prat"
    "prateek"
    "teek"
    

*******************************************************************************/

#include <iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
string keypad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Node {
public:
    char data;
    unordered_map<char, Node*> m;
    bool isTerminal;
    string s;
    
    // constructor
    Node(char d) {
        data = d;
        isTerminal = false;
        s = "";
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
        curr_node->s = word;
    }
};


void insertIfValid(Node *curr_node, string phoneNumber, int i, unordered_set<string> &output) {
    
    // base case
    if(curr_node->isTerminal) {
        output.insert(curr_node->s);
    }
    
    if(i == phoneNumber.length()) {
        return;
    }
    
    // recursive case
    int digit = phoneNumber[i] - '0'; 
    string possible_letters = keypad[digit];
    for(char letter : possible_letters) {
        if(curr_node->m.count(letter) != 0) {
            insertIfValid(curr_node->m[letter], phoneNumber, i+1, output);
        }
    }
}

vector<string> filterNames(string phoneNumber, vector<string> words){
    
    // insert every word in Trie
    Trie t;
    for(string word : words) {
        t.insert(word);
    }
    
    // for every number in phone numbe 
    unordered_set<string> output;
    for(int i=0; i<phoneNumber.length(); i++) {
        Node *curr_node = t.getRoot();
        insertIfValid(curr_node, phoneNumber, i, output);
    }
    
    return vector<string>(output.begin(), output.end());
    
}

int main() {
    
    string phoneNumber = "7728335";
    vector<string> words = {"prat", "prateek", "codingminutes", "code", "prat335", "teek"};
    vector<string> output = filterNames(phoneNumber, words);
    
    for(string word : output) {
        cout<<word<<endl;
    }

    return 0;
}
