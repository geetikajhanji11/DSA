/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
    vector<int> dy = {-1, 1, 0, 0, 1, -1, 1, -1};

    bool inBounds(int &i, int &j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // base case
        if(grid[0][0] == 1) return -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // {i, j, path_length}
        queue<vector<int>> q;
        q.push({0, 0, 1});
        visited[0][0] = true;

        while(!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int pathLength = q.front()[2];
            q.pop();

            // reached end
            if(i == n-1 && j == n-1) {
                return pathLength;
            }

            for(int k=0; k<8; k++) {
                int next_i = i + dx[k];
                int next_j = j + dy[k];

                if(!inBounds(next_i, next_j, grid)) continue;
                if(visited[next_i][next_j]) continue;
                if(grid[next_i][next_j] == 1) continue;

                q.push({next_i, next_j, pathLength + 1});
                visited[next_i][next_j] = true;
            }
        }

        return -1;
    }
};