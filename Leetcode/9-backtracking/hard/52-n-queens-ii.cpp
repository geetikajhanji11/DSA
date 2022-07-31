/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool can_place_queen_at(int i, int j, vector<string> grid) {

    // check column
    for(int row=i; row>=0; row--) {
        if(grid[row][j] == 'Q') return false;
    }

    // check left diagonal
    int row = i;
    int col = j;
    while(row >= 0 && col >= 0) {
        if(grid[row][col] == 'Q') return false;
        row--;
        col--;
    }

    // check right diagonal
    row = i;
    col = j;
    while(row >= 0 && col < grid.size()) {
        if(grid[row][col] == 'Q') return false;
        row--;
        col++;
    }

    // queen can be placed
    return true;
}


void solve(int i, vector<string> grid, int &total, int &n) {
    if(i == n) {
        total++;
        return;
    }

    for(int j=0; j<n; j++) {
        if(can_place_queen_at(i, j, grid)) {
            grid[i][j] = 'Q';
            solve(i+1, grid, total, n);
            grid[i][j] = '.';
        }
    }
}


int totalNQueens(int n) {
    vector<string> grid;
    for(int i=0; i<n; i++) {
        string s = "";
        for(int j=0; j<n; j++) {
            s.push_back('.');
        }
        grid.push_back(s);
    }

    int total = 0;
    solve(0, grid, total, n);
    return total; 
}



int main() {

    auto res = totalNQueens(4);
    cout<<res;

    return 0;
}