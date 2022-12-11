/*******************************************************************
Given grid: 0 empty cell, 1 fresh orange, 2 rotten orange
Return min # of minutes until no cell has a fresh orange

BFS => rotten will contaminate neighbors first, then propagate out

Time: O(m x n)
Space: O(m x n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {-1, 1, 0, 0};

bool in_bounds(int i, int j, vector<vector<int>>& grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

int orangesRotting(vector<vector<int>>& grid) {
    
    int rows = grid.size();
    int cols = grid[0].size();

    

    // initially populate queue with all the
    // positions of rotten oranges
    queue<pair<int,int>> q; 
    int fresh_oranges = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            // if the orange is rotten, put in queue
            if(grid[i][j] == 2) q.push({i, j});
            // count fresh oranges total
            if(grid[i][j] == 1) fresh_oranges++;
        }
    }

    q.push({-1,-1});

    // do bfs for every rotten orange in queue
    int minutes = 0;
    int fresh_oranges_now_rotten = 0;
    while(!q.empty()) {

        while(q.front().first != -1 && q.front().second != -1) {

            auto rotten_orange = q.front();
            q.pop();
            
            int i = rotten_orange.first;
            int j = rotten_orange.second;

            for(int k=0; k<4; k++) {
                int next_i = i + dx[k];
                int next_j = j + dy[k];
                if(!in_bounds(next_i, next_j, grid)) continue;
                if(grid[next_i][next_j] == 1) {
                    grid[next_i][next_j] = 2;
                    fresh_oranges_now_rotten++;
                    q.push({next_i, next_j});
                }
            }

        }

        q.pop();
        q.push({-1,-1});
        if(q.size() == 1) break;

        minutes++;

    }

    if(fresh_oranges != fresh_oranges_now_rotten) return -1;
    return minutes;
}

int main() {

    // vector<vector<int>> grid = {
    //     {2,1,1},
    //     {1,1,0},
    //     {0,1,1}
    // };

vector<vector<int>> grid = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };

    cout<<orangesRotting(grid);
    return 0;
}