/*******************************************************************
Given grid: -1 wall, 0 gate, INF empty, fill each empty w/ dist to nearest gate

BFS traversal, shortest path from each gate to all empty rooms
Each gate only looks at within 1 space, then next gate, guarantees shortest

Time: O(m x n)
Space: O(m x n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool in_bounds(int i, int j, vector<vector<int>> &rooms) {
    return i >= 0 && i < rooms.size() && j >= 0 && j < rooms[0].size();
}

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

// *********** BFS SOLUTION ***********
// TIME: O(M x N) 
// SPACE: O(M x N)

void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size();
    int n = rooms[0].size();
    
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rooms[i][j] == 0) {
                q.push({i, j});
            }
        }
    }
    
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            
            if (!in_bounds(next_i, next_j, rooms) || rooms[next_i][next_j] != INT_MAX) {
                continue;
            }
            
            rooms[next_i][next_j] = rooms[i][j] + 1;
            q.push({next_i, next_j});
        }
    }
}


// *********** DFS SOLUTION ***********
// TIME: O(MN) [i guess]
// SPACE: O(1)

void dfs(int i, int j, int distance, vector<vector<int>> &rooms) {

    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];

        if(!in_bounds(next_i, next_j, rooms)) continue;

        if(rooms[next_i][next_j] == -1) continue;
        if(rooms[next_i][next_j] == 0) continue;

        int nextDistance = distance + 1; 
        if(nextDistance < rooms[next_i][next_j]) {
            rooms[next_i][next_j] = nextDistance;
            dfs(next_i, next_j, nextDistance, rooms);
        }

    }
}

void wallsAndGates(vector<vector<int>> &rooms) {
    int rows = rooms.size();
    int cols = rooms[0].size();

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {

            if(rooms[i][j] == 0) {
                dfs(i, j, 0, rooms);
            }
        }
    }

}

int main() {

    return 0;
}