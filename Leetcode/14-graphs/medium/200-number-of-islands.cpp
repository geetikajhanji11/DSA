#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

bool in_bounds(int i, int j, vector<vector<char>>& grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

void dfs(int i, int j, vector<vector<char>>& grid) {

    if(!in_bounds(i, j, grid)) return;
    if(grid[i][j] == '0') return;

    grid[i][j] = '0';

    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        dfs(next_i, next_j, grid);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;

    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                islands++;
                dfs(i, j, grid);
            }
        }
    }

    return islands;
}

int main() {

    return 0;
}