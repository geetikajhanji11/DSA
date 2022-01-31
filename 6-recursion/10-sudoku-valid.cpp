/**************************************************************

Valid Sudoku (Not checked)

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells 
need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the 
digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is 
not necessarily solvable.
Only the filled cells need to be validated according to the 
mentioned rules.

Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
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

bool isValid(vector<vector<int>> &board) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int num = board[i][j];
            board[i][j] = 0;
            if(num != 0 && !isValidSudoku(board, i, j, num)) return false;
            board[i][j] = num;
        }
    }
    return true;
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
    isValid(board);
    return 0;
    
}