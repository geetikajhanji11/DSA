/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Cell {
public:
    int i;
    int j;
    int pathLength;
    int obstaclesSeen;
    Cell(int i, int j, int pathLength, int obstaclesSeen) {
        this->i = i;
        this->j = j;
        this->pathLength = pathLength;
        this->obstaclesSeen = obstaclesSeen;
    }
};

class Solution {

    bool inBounds(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        // acts as a visited array as well as an array
        // that keeps track of the number of obstacles seen
        // at a particular cell from any previous path 
        vector<vector<int>> obstaclesAt(rows, vector<int>(cols, -1));

        queue<Cell> q;
        q.push(Cell(0, 0, 0, 0));

        while(!q.empty()) {
            Cell currCell = q.front(); q.pop();

            // reached the destination
            if(currCell.i == rows - 1 && currCell.j == cols - 1) {
                return currCell.pathLength;
            }

            // for every neighbour of current cell
            for(int ctr=0; ctr<4; ctr++) {
                int next_i = currCell.i + dx[ctr];
                int next_j = currCell.j + dy[ctr];

                // out of bounds
                if(!inBounds(next_i, next_j, grid)) continue;

                // next cell is an obstacle
                int nextObstaclesSeen = currCell.obstaclesSeen;
                if(grid[next_i][next_j] == 1) {
                    if(currCell.obstaclesSeen + 1 > k) continue;
                    nextObstaclesSeen += 1;
                }
                
                // cell has been visited before
                if(obstaclesAt[next_i][next_j] != -1) {
                    if(obstaclesAt[next_i][next_j] <= nextObstaclesSeen) {
                        continue;
                    }
                }

                // update the obstaclesAt array and insert in queue
                obstaclesAt[next_i][next_j] = nextObstaclesSeen;
                q.push(Cell(next_i, next_j, currCell.pathLength + 1, nextObstaclesSeen));
            }
        }

        return -1;
    }
};