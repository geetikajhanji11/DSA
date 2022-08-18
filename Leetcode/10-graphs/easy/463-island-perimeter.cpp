/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool in_bounds(int i, int j, vector<vector<int>>& grid) {
    return i >= 0 && i <grid.size() && j >= 0 && j <grid[0].size();
}

int islandPerimeter(vector<vector<int>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    int ctr = 0;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(grid[i][j] == 0) continue;

            // grid[i][j] = 1
            int strips = 0;
            for(int k=0; k<4; k++) {
                int next_i = i + dx[k];
                int next_j = j + dy[k];
                if(!in_bounds(next_i, next_j, grid)) {
                    strips++;
                    continue;
                }
                if(grid[next_i][next_j] == 0) {
                    strips++;
                }
            }
            ctr += strips;
        }
    }

    return ctr;
}