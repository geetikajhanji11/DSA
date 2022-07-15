/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {0,0,1,-1};
vector<int> dy = {-1,1,0,0};

bool in_bounds(int i, int j, vector<vector<int>>& grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

int get_area(int i, int j, vector<vector<int>>& grid) {

    if(!in_bounds(i, j, grid)) return 0;
    if(grid[i][j] == 0) return 0;

    grid[i][j] = 0;
    int area = 0;
    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        area += get_area(next_i, next_j, grid);
    }

    return area + 1;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {

    int largest_area = 0;
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j] == 1) {
                int curr_area = get_area(i, j, grid);
                largest_area = max(largest_area, curr_area);
            }

        }
    }
    return largest_area;
}

int main() {

    return 0;
}