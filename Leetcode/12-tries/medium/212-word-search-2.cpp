/*******************************************************************
 * 
 *  MY SOLUTION IS CORRECT BUT SHOWS TIME LIMIT EXCEEDED
 *  SO FOLLOW THIS INSTEAD
 * 
 * Given a board of characters & a list of words, return all words on the board
 * Implement trie, for search: iterate thru children until isWord, add to result
 * Time: O(m x (4 x 3^(l - 1))) -> m = # of cells, l = max length of words
 * Space: O(n) -> n = total number of letters in dictionary (no overlap in Trie)

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        
        int m = board.size();
        int n = board[0].size();
        
        TrieNode* node = root;
        vector<string> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, node, "", result);
            }
        }
        
        return result;
    }
private:
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        
        node->isWord = true;
    }
    
    void search(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* node, string word, vector<string>& result) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
            return;
        }
        
        char c = board[i][j];
        
        node = node->children[c - 'a'];
        if (node == NULL) {
            return;
        }
        
        word += board[i][j];
        if (node->isWord) {
            result.push_back(word);
            node->isWord = false;
        }
        
        board[i][j] = '#';
        
        search(board, i - 1, j, m, n, node, word, result);
        search(board, i + 1, j, m, n, node, word, result);
        search(board, i, j - 1, m, n, node, word, result);
        search(board, i, j + 1, m, n, node, word, result);
        
        board[i][j] = c;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    string word;

    TrieNode(char ch) {
        this->ch = ch;
        this->isTerminal = false;
        this->word = "";
        for(int i=0; i<26; i++) children[i] = NULL;
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
            if(temp->children[ch - 'a'] == NULL) {
                temp->children[ch - 'a'] = new_TrieNode;
            } 
            temp = temp->children[ch - 'a'];
        }
        temp->isTerminal = true;
        temp->word = word;
    }

};

bool in_bounds(int i, int j, vector<vector<char>>& board) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
}

void dfs(int i, int j, vector<vector<char>>& board, TrieNode* root, unordered_set<string> &result_set, vector<vector<int>> visited, unordered_set<string> &words_set) {

    if(root->isTerminal) {
        result_set.insert(root->word);
        words_set.erase(root->word);
    }

    if(words_set.empty()) return;

    char curr_ch = board[i][j];
    visited[i][j] = true;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0, 0};

    for(int k=0; k<4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if(!in_bounds(x, y, board)) continue;
        char next_ch = board[x][y];
        if(!visited[x][y] && root->children[next_ch - 'a'] != NULL) {
            dfs(x, y, board, root->children[next_ch - 'a'], result_set, visited, words_set);
        }
    }

    visited[i][j] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;

    unordered_set<string> words_set;
    for(string word : words) {
        trie.insert(word);
        words_set.insert(word);
    }

    int rows = board.size();
    int cols = board[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    unordered_set<string> result_set;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            char ch = board[i][j];
            if(trie.root->children[ch - 'a'] != NULL) {
                dfs(i, j, board, trie.root->children[ch - 'a'], result_set, visited, words_set);
            }
        }
    }

    vector<string> result(result_set.begin(), result_set.end());
    return result;
}

int main() {

    return 0;
}

