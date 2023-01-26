/*******************************************************************
I think one of the crucial points that is not well explained is that 
the "suffix trie" is actually a "reversed suffix trie". 

Words are put in the trie backwards and the remaining prefix is checked 
if it is a palindrome. If it is, its index is recorded in the 
palindromeIndexes; these prefixes are effectively the middle portion 
of a combined palindrome checked later. For example if we enter sssll 
then after adding lls (reversed) the remaining palindromic ss prefix 
causes the node lls to contain the index of the word in palindromeIndexes.

After building this trie, words are looked up front to back. 
Suppose we check the word lls. We get to the node, look up the 
palindromeIndexes and find a pointer to sssll as per the explanation above. 

So the combined word starts with lls, ends with the reversed version of 
lls and has a palindrome in between (ss) resulting again in another palindrome.

However, also during the loop we need to check if the reversed version 
is in the trie. Suppose we have cba and abcll. 

The first causes to have abc in the trie. 
When iterating through abcll we will end up at node abc at some point. 
The index tells us that it is actually a valid reversed word. 
Then we only need to check for the remainder ll being a palindrome and if it is, 
it means that together it's also a palindrome (abc + ll + cba).

https://leetcode.com/problems/palindrome-pairs/solutions/2585494/c-trie-related-problems/
user5865d
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// **************** DISCUSS SOLUTION **************** 
bool isPalindrome(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// TrieNode data structure
class TrieNode {
public:
    vector<TrieNode*> children; 
    int index = -1; // indicates whether it is terminal or not (index != -1 => terminal)
    vector<int> palindromeIndexes; // remaining prefix is checked if it is a palindrome. If it is, its index is recorded 

    TrieNode() {
        children.resize(26);
    }
};

// Trie
// Suffix trie
class Trie {
public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // "reversed suffix trie"
    // enter words in reverse manner
    void add(string &s, int i) {
        TrieNode* temp = root;

        // from end to begin
        for (int j=s.size()-1; j>=0; j--) {

            // A[i]'s prefix forms a palindrome
            if(isPalindrome(s, 0, j)) {
                temp->palindromeIndexes.push_back(i); 
            } 

            // travese trie 
            int letter = s[j] - 'a';
            if (!temp->children[letter]) {
                temp->children[letter] = new TrieNode();
            }

            temp = temp->children[letter];
        }

        // end of current word
        temp->index = i;

        // A[i]'s prefix is empty string here, which is a palindrome.
        temp->palindromeIndexes.push_back(i); 
    }

};

class Solution {
    
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        
        Trie t;
        for (int i=0; i<A.size(); i++) {
            t.add(A[i], i);
        }

        vector<vector<int>> result;

        for(int i=0; i<A.size(); i++) {
            string s = A[i];
            TrieNode* temp = t.root;

            for(int j=0; j<s.size() && temp; j++) {

                // currently matched till A[i]'s 0...j-1 
                // also check if j...size-1 is palindrome too
                // include in result
                if(temp->index != -1 && temp->index != i && isPalindrome(s, j, s.size() - 1)) {
                    result.push_back({ i, temp->index }); 
                }

                // A[i]'s prefix matches this word and 
                // A[i]'s suffix forms a palindrome
                temp = temp->children[s[j] - 'a'];
            }

            if (!temp) continue;

            for (int j : temp->palindromeIndexes) { 
                // A[i] is exhausted in the matching above. 
                // If a word whose prefix is palindrome after 
                // matching its suffix with A[i], 
                // then this is also a valid pair
                if (i != j) result.push_back({ i, j });
            }

        }

        return result;
    }
};

