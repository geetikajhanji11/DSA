/*******************************************************************
Determine if a 9x9 Sudoku board is valid (no repeats)

Hash set to store seen values, check rows, cols, blocks

Time: O(n^2)
Space: O(n^2)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_row_valid(int row, vector<vector<char>>& board) {
    unordered_set<char> s;
    for(int j=0; j<board[0].size(); j++) {
        char ch = board[row][j];
        if(ch == '.') continue;
        if(s.find(ch) != s.end()) return false;
        s.insert(ch);
    }
    return true;
}

bool is_column_valid(int col, vector<vector<char>>& board) {
    unordered_set<char> s;
    for(int i=0; i<board.size(); i++) {
        char ch = board[i][col];
        if(ch == '.') continue;
        if(s.find(ch) != s.end()) return false;
        s.insert(ch);
    }
    return true;
}

bool is_small_grid_valid(int row, int col, vector<vector<char>>& board) {
    unordered_set<char> s;
    for(int i=row; i<row+3; i++) {
        for(int j=col; j<col+3; j++) {
            char ch = board[i][j];
            if(ch == '.') continue;
            if(s.find(ch) != s.end()) return false;
            s.insert(ch);
        }
    } 
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {

    int rows = board.size();
    int cols = board[0].size();

    for(int i=0; i<rows; i++) {
        if(!is_row_valid(i, board)) return false;
    }

    for(int j=0; j<cols; j++) {
        if(!is_column_valid(j, board)) return false;
    }

    for(int i=0; i<rows; i=i+3) {
        for(int j=0; j<cols; j=j+3) {
            if(!is_small_grid_valid(i, j, board)) return false;
        }
    }
    return true;
}

int main() {

    return 0;
}