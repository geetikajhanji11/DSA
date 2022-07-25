/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool can_place_queen_at(int i, int j, vector<string> &grid) {

    // check column
    for(int k=i; k>=0; k--) {
        if(grid[k][j] == 'Q') return false;
    }

    // check left diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0) {
        if(grid[x][y] == 'Q') return false;
        x--;
        y--;
    }

    // check right diagonal
    x = i;
    y = j;
    while(x >= 0 & y < grid[0].size()) {
        if(grid[x][y] == 'Q') return false;
        x--;
        y++;
    }
    return true;
}

void solve(int i, vector<string> &grid, vector<vector<string>> &result) {

    int n = grid.size();

    if(i == n) {
        result.push_back(grid);
        return;
    }

    for(int j=0; j<n; j++) {
        if(can_place_queen_at(i, j, grid)) {
            grid[i][j] = 'Q';
            solve(i+1, grid, result);
            grid[i][j] = '.';
        }
    }

}

vector<vector<string>> solveNQueens(int n) {
    vector<string> grid;
    for(int i=0; i<n; i++) {
        string row = "";
        for(int j=0; j<n; j++) {
            row += '.';
        }
        grid.push_back(row);
    }

    vector<vector<string>> result;

    solve(0, grid, result);

    return result;

}

int main() {

    return 0;
}