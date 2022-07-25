/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board, int i, int j, char num) {

    // check if number is in the same row or column
    for(int k=0; k<9; k++) {
        if(board[k][j] == num || board[i][k] == num) 
            return false;
    }

    // check if number is in the small 3 x 3 grid 
    // to which it belongs
    int row = i;
    int col = j;
    while(col % 3 != 0) col--;
    while(row % 3 != 0) row--;
    for(int xi=0; xi<3; xi++) {
        for(int xj=0; xj<3; xj++) {
            if(board[xi+row][xj+col] == num) return false;
        }
    }

    return true;
}

void printBoard(vector<vector<char>>& board) {
    for(auto v : board) {
        for(auto c : v) cout<<c<<" ";
        cout<<endl;
    }
}

bool solve(int i, int j, vector<vector<char>>& board) {

    if(i == board.size()) {
        printBoard(board);
        return true;
    }

    if(j == board[0].size()) {
        return solve(i+1, 0, board);
    }

    if(board[i][j] != '.') {
        return solve(i, j+1, board);
    }

    if(board[i][j] == '.') {
        for(int num=1; num<=9; num++) {
            if(isValidSudoku(board, i, j, (char) (num + 48))) {
                board[i][j] = (char) (num + 48);
                bool can_solve_rest = solve(i, j+1, board);
                if(can_solve_rest) return true;
            }
        }
    }

    board[i][j] = '.';
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(0, 0, board);
}

int main() {

    char ch = (char) 1 + 48;
    cout<<ch;
    return 0;
}