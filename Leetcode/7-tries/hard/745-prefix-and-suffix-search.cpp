/*******************************************************************
Trie solution with improvement:
------------------------------

Take "apple" as an example, we will insert add 
    "apple{apple", 
    "pple{apple", 
    "ple{apple", 
    "le{apple", 
    "e{apple", 
    "{apple" 
into the Trie Tree.

If the query is: prefix = "app", suffix = "le", 
we can find it by querying our trie for "le { app".

We use '{' because in ASCii Table, 
'{' is next to 'z', so we just need to create new TrieNode[27] 
instead of 26. 
Also, compared with tradition Trie, we add the attribute 
weight in class TrieNode.

// ********** CODE **********
class TrieNode {
    TrieNode[] children;
    int weight;
    public TrieNode() {
        children = new TrieNode[27]; // 'a' - 'z' and '{'. 'z' and '{' are neighbours in ASCII table
        weight = 0;
    }
}

public class WordFilter {
    TrieNode root;
    public WordFilter(String[] words) {
        root = new TrieNode();
        for (int weight = 0; weight < words.length; weight++) {
            String word = words[weight] + "{";
            for (int i = 0; i < word.length(); i++) {
                TrieNode cur = root;
                cur.weight = weight;
                // add "apple{apple", "pple{apple", "ple{apple", "le{apple", "e{apple", "{apple" into the Trie Tree
                for (int j = i; j < 2 * word.length() - 1; j++) {
                    int k = word.charAt(j % word.length()) - 'a';
                    if (cur.children[k] == null)
                        cur.children[k] = new TrieNode();
                    cur = cur.children[k];
                    cur.weight = weight;
                }
            }
        }
    }
    public int f(String prefix, String suffix) {
        TrieNode cur = root;
        for (char c: (suffix + '{' + prefix).toCharArray()) {
            if (cur.children[c - 'a'] == null) {
                return -1;
            }
            cur = cur.children[c - 'a'];
        }
        return cur.weight;
    }
}
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ********************** HASHMAP SOLUTION ********************** 
class WordFilter {

    // stores all combinations of prefix & suffix of a word
    // pref|suff = index
    unordered_map<string, int> hashMap;

public:
    WordFilter(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            for(int prefLen=1; prefLen<=word.length(); prefLen++) {
                string prefix = word.substr(0, prefLen);
                for(int j=word.length()-1; j>=0; j--) {
                    string suffix = word.substr(j, word.length());
                    hashMap[prefix + "|" + suffix] = i;
                }
            }    
        }
    }
    
    int f(string pref, string suff) {
        string key = pref + "|" + suff;
        if(hashMap.find(key) == hashMap.end()) return -1;
        return hashMap[key];
    }
};


/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

// ********************** TLE ********************** 
class TrieNode {
public:
    TrieNode* children[26];
    unordered_set<int> indexes; // indexes where the word ends
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class WordFilter {

    TrieNode* prefixRoot;
    TrieNode* suffixRoot;

    void addWord(string word, int index) {

        TrieNode* node;
        
        // adding to PREFIX Trie
        node = prefixRoot;
        for (int i = 0; i < word.size(); i++) {
            int curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
            node->indexes.insert(index);
        }

        // adding to SUFFIX Trie
        node = suffixRoot;
        for (int i = word.size()-1; i >= 0; i--) {
            int curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
            node->indexes.insert(index);
        }
    }

    unordered_set<int> searchInPrefixTrie(string pref) {
        TrieNode* node = prefixRoot;
        
        for(int i=0; i<pref.length(); i++) {
            int curr = pref[i] - 'a';
            if(node->children[curr] == NULL) return {};
            node = node->children[curr];
        }

        return node->indexes;
    }

    unordered_set<int> searchInSuffixTrie(string suff) {
        TrieNode* node = suffixRoot;
        
        for(int i=suff.length()-1; i>=0; i--) {
            int curr = suff[i] - 'a';
            if(node->children[curr] == NULL) return {};
            node = node->children[curr];
        }

        return node->indexes;
    }

public:
    WordFilter(vector<string>& words) {
        prefixRoot = new TrieNode();
        suffixRoot = new TrieNode();

        for(int i=0; i<words.size(); i++) {
            addWord(words[i], i);
        }
    }
    
    int f(string pref, string suff) {
        unordered_set<int> prefixIndexes = searchInPrefixTrie(pref);
        unordered_set<int> suffixIndexes = searchInSuffixTrie(suff);

        int maxIndex = -1;

        for(int index : prefixIndexes) {
            if(suffixIndexes.find(index) != suffixIndexes.end()) {
                maxIndex = max(maxIndex, index);
            }
        }

        return maxIndex;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */