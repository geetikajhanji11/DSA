/**************************************************************

SUDOKU SOLVER

Input:
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    }

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

void printBoard(vector<vector<int>> &board) {
    for(auto row : board) {
        for(int num : row) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

bool isValidSudoku(vector<vector<int>> &board, int i, int j, int num) {

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


bool solveSudoku(vector<vector<int>> &board, int i, int j) {
    
    // base case
    if(i == 9) {
        cout<<"Solved\n";
        printBoard(board);
        return true;
    }
    
    // if reached last column
    if(j == 9) {
        return solveSudoku(board, i+1, 0);
    }

    // if cell is already filled
    if(board[i][j] != 0) {
        return solveSudoku(board, i, j+1);
    }

    // cell has to be filled
    // try all possibilities
    for(int num=1; num<=9; num++) {
        if(isValidSudoku(board, i, j, num)) {
            board[i][j] = num;
            bool success = solveSudoku(board, i, j+1);
            if(success) return true;
        }
    }

    board[i][j] = 0;
    return false;
}



// main function 
int main() {
    
    vector<vector<int>> board {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };
    solveSudoku(board, 0, 0);
    return 0;
    
}