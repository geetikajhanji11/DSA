/*******************************************************************
 * LARGEST ISLAND
 * 
 * Given a 2D grid, each cell of which contains either 0 or 1.
 * Each 1 represents land and 0 represents water. Each land piece
 * (x, y) is connected to its 4 neighbours (Left, Right, Up, Down).
 * Your task is to find the size of largest island - size of the 
 * island is given by the number of 1s of that island. Your code
 * should return 0 if no island is present.

 * SAMPLE INPUT
 * grid = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0}
    };

 * OUTPUT
 * 8
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/**************** DFS & BACKTRACKING SOLUTION ****************/
bool cellInBounds(int i, int j, int rows, int cols) {
    if(i >= 0 && i < rows && j >= 0 && j < cols) return true;
    return false;
}

int dfs(vector<vector<int> > &grid, int i, int j) {

    int rows = grid.size();
    int cols = grid[0].size();
    if(!cellInBounds(i, j, rows, cols)) return 0;

    // current cell is water (0)
    if(grid[i][j] == 0) return 0;

    // current cell is land (1)
    // mark is as 0 to indicate
    // that this cell is visited
    grid[i][j] = 0;

    // 4 directions => up, down, left, right
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int size = 1;
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        size += dfs(grid, next_i, next_j);
        
    }

    return size;
}

int largest_island(vector<vector<int> > grid){
    
    int rows = grid.size();
    int cols = grid[0].size();
    int largest_size = 0;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(grid[i][j] == 1) {
                int curr_size = dfs(grid, i, j);
                largest_size = max(largest_size, curr_size);
            }
        }
    }
    
    return largest_size;
    
}

int main() {

    vector<vector<int>> grid = {
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 1, 0}
    };

    cout<<"Largest Island = "<<largest_island(grid);
    
    return 0;
}