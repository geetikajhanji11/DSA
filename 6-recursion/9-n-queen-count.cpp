/**************************************************************

N QUEEN

Place N chess queens on an N x N chessboard so that no 2 queens
can attack each other.

Input:
    n = 4

Output:
    {
        {" ", "Q", " ", " "},
        {" ", " ", " ", "Q"},
        {"Q", " ", " ", " "},
        {" ", " ", "Q", " "},
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

bool canPlaceQueen(vector<vector<char>> &grid, int n, int i, int j) {

    if(i < 0 || i >= n || j < 0 || j >= n) return false;
    
    int row = 0;
    int col = 0;

    // checking along column
    for(row = 0; row < i; row++) {
        if(grid[row][j] == 'Q') return false;
    }

    // checking along left diagonals
    row = i;
    col = j;
    while(row >= 0 && col >= 0) {
        if(grid[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // checking along right diagonals
    row = i;
    col = j;
    while(row >= 0 && col < n) {
        if(grid[row][col] == 'Q') return false;
        row--;
        col++;
    }

    return true;
}



void solveNQueen(vector<vector<char>> &grid, int n, int i, int &count) {
    // base case
    if(i == n) {
        count = count + 1;
        return;
    }

    // recursive case
    for(int j=0; j<n; j++) {
        if(canPlaceQueen(grid, n, i, j)) {
            grid[i][j] = 'Q';
            solveNQueen(grid, n, i+1, count);
            grid[i][j] = '_';
        }
    }
}


int NQueen(int n) {
    vector<vector<char>> grid(n, vector<char>(n, '_'));
    int count = 0;
    solveNQueen(grid, n, 0, count);
    return count;
}


// main function 
int main() {
    
    int count = NQueen(4);
    cout<<"\nAnswer: "<<count;

    return 0;
    
}