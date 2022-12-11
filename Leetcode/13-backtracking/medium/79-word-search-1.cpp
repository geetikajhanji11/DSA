/*******************************************************************
 * 
 *  MY SOLUTION IS CORRECT BUT SHOWS TIME LIMIT EXCEEDED
 *  SO FOLLOW THIS INSTEAD
 * 
 * Given a char board & a word, return true if word exists in the grid
 * DFS traversal, set visited cells to '#', search in 4 directions, backtrack
 * Time: O(n x 3^l) -> n = # of cells, l = length of word
 * Space: O(l)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j, m, n)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word,
        int index, int i, int j, int m, int n) {
        
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        
        board[i][j] = '#';
        
        if (dfs(board, word, index + 1, i - 1, j, m, n)
            || dfs(board, word, index + 1, i + 1, j, m, n)
            || dfs(board, word, index + 1, i, j - 1, m, n)
            || dfs(board, word, index + 1, i, j + 1, m, n)) {
            return true;
        }
        
        board[i][j] = word[index];
        return false;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool in_bounds(int i, int j, vector<vector<char>>& board) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
}

bool dfs(int i, int j, int idx, string &word, vector<vector<char>>& board, vector<vector<int>> visited) {
  
    char curr_ch = board[i][j];
    visited[i][j] = true;

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0, 0};

    for(int k=0; k<4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        int next_idx = idx + 1;

        if(next_idx == word.length()) return true;
        if(!in_bounds(x, y, board)) continue;

        char next_ch = board[x][y];
        if(!visited[x][y] && next_ch == word[next_idx]) {
            if(dfs(x, y, next_idx, word, board, visited)) return true;
        }
    }

    visited[i][j] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
      
    int rows = board.size();
    int cols = board[0].size();
    
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    unordered_set<string> result_set;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(word[0] == board[i][j]) {
                if(dfs(i, j, 0, word, board, visited)) return true;
            }
        }
    }

    return false;
}

int main() {

    return 0;
}