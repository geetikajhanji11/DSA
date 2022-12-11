/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    bool inBounds(int &i, int &j, vector<vector<int>> &grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    // dfs for exploring the first island
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, queue<vector<int>> &q) {

        visited[i][j] = true;
        q.push({i, j});

        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];

            if(!inBounds(next_i, next_j, grid)) continue;
            if(visited[next_i][next_j]) continue;
            if(grid[next_i][next_j] == 0) continue;

            dfs(next_i, next_j, grid, visited, q);
        }
    }

    // bfs on every cell of first island up until it
    // touches the perimeter of the second island
    int bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, queue<vector<int>> &q) {
        int flips = 0;
        while(!q.empty()) {
            
            int size = q.size();

            while(size != 0) {
                int i = q.front()[0];
                int j = q.front()[1];
                q.pop();

                for(int k=0; k<4; k++) {
                    int next_i = i + dx[k];
                    int next_j = j + dy[k];
                    
                    if(!inBounds(next_i, next_j, grid)) continue;
                    if(visited[next_i][next_j]) continue;
                    
                    if(grid[next_i][next_j] == 1) {
                        return flips;
                    }
                    
                    visited[next_i][next_j] = true;
                    q.push({next_i, next_j});
                }
                size--;
            }

            flips++;
        }

        return flips;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {

        // dimensions
        int rows = grid.size();
        int cols = grid[0].size();

        // contains positions of grid that are visited
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        // put all first island positions in queue
        // 0 => i
        // 1 => j
        queue<vector<int>> q;

        // find first island and run dfs
        bool foundIsland = false;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                // found first island
                // run dfs on it
                if(grid[i][j] == 1) {
                    dfs(i, j, grid, visited, q);
                    foundIsland = true;
                    break;
                }
            }
            if(foundIsland) break;
        }    
        
        // run bfs on queue
        return bfs(grid, visited, q);

    }
};