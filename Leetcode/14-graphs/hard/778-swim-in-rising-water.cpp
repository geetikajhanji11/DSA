/*******************************************************************
Given an integer elevation matrix, rain falls, at time t, 
depth everywhere is t
Can swim iff elevation at most t, return least time get 
from top left to bottom right

Shortest path w/ min heap: 
at every step, find lowest water level to move forward

Time: O(n^2 log n)
Space: O(n^2)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Cell {
public:
    int maxHeight;
    int i;
    int j;
    Cell(int height, int i, int j) {
        this->maxHeight = height;
        this->i = i;
        this->j = j;
    }
};

class Compare {
public:
    bool operator()(Cell a, Cell b) {
        return a.maxHeight > b.maxHeight;
    }
};

bool in_bounds(int i, int j, vector<vector<int>>& grid) {
    return i >=0 && i < grid.size() && j >=0 && j < grid[0].size();
}

int swimInWater(vector<vector<int>>& grid) {
        
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Cell, vector<Cell>, Compare> minHeap;
    vector<vector<int>> visited(rows, vector<int>(cols, 0));

    minHeap.push(Cell(grid[0][0], 0, 0));
    visited[0][0] = true;

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    while(!minHeap.empty()) {
        Cell currCell = minHeap.top();
        minHeap.pop();

        if(currCell.i == rows-1 && currCell.j == cols-1) {
            return currCell.maxHeight;
        }

        for(int k=0; k<4; k++) {
            int next_i = currCell.i + dx[k];
            int next_j = currCell.j + dy[k];

            if(!in_bounds(next_i, next_j, grid)) continue;
            if(visited[next_i][next_j]) continue;

            Cell nextCell = Cell(max(currCell.maxHeight, grid[next_i][next_j]), next_i, next_j);
            minHeap.push(nextCell);
            visited[next_i][next_j] = true;
        }
    }

    return -1;

}

int main() {

    return 0;
}