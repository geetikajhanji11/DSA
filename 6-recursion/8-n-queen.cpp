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



bool solveNQueen(vector<vector<char>> &grid, int n, int i) {
    // base case
    if(i == n) return true;

    // recursive case
    for(int j=0; j<n; j++) {
        if(canPlaceQueen(grid, n, i, j)) {
            grid[i][j] = 'Q';
            bool success = solveNQueen(grid, n, i+1);
            if(success) return true;
            else {
                grid[i][j] = '_';
            }
        }
    }
    return false;
}


vector<vector<char>> NQueen(int n) {
    vector<vector<char>> grid(n, vector<char>(n, '_'));
    solveNQueen(grid, n, 0);
    return grid;
}


// main function 
int main() {
    
    vector<vector<char>> result = NQueen(4);
    for(auto r : result) {
        for(char ch : r) {
            cout<<ch<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}