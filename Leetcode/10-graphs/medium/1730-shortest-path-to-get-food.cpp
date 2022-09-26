/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool inBounds(int &i, int &j, vector<vector<string>> &grid) {
    return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
}

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

pair<int, int> getStart(vector<vector<string>> &grid) {
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j] == "*") {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int getFood(vector<vector<string>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // vector => i, j, steps
    queue<vector<int>> q;
    auto start = getStart(grid);

    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while(!q.empty()) {

        int i = q.front()[0];
        int j = q.front()[1];
        int steps = q.front()[2];
        q.pop();

        if(grid[i][j] == "#") {
            return steps;
        }

        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];

            if(!inBounds(next_i, next_j, grid)) continue;
            if(visited[next_i][next_j]) continue;
            if(grid[next_i][next_j] == "X") continue;

            q.push({next_i, next_j, steps + 1});
            visited[next_i][next_j] = true;
        }
    }

    return -1;
} 

int main() {

    vector<vector<string>> grid1 = {
        {"X","X","X","X","X","X"},
        {"X","*","O","O","O","X"},
        {"X","O","O","#","O","X"},
        {"X","X","X","X","X","X"}
    };

    vector<vector<string>> grid2 = {
        {"X","X","X","X","X"},
        {"X","*","X","O","X"},
        {"X","O","X","#","X"},
        {"X","X","X","X","X"}
    };

    vector<vector<string>> grid3 = {
        {"X","X","X","X","X","X","X","X"},
        {"X","*","O","X","O","#","O","X"},
        {"X","O","O","X","O","O","X","X"},
        {"X","O","O","O","O","#","O","X"},
        {"X","X","X","X","X","X","X","X"}
    };

    vector<vector<string>> grid4 = {
        {"O","*"},
        {"#","O"}
    };

    vector<vector<string>> grid5 = {
        {"X","*"},
        {"#","X"}
    };


    cout<<getFood(grid1)<<endl;
    cout<<getFood(grid2)<<endl;
    cout<<getFood(grid3)<<endl;
    cout<<getFood(grid4)<<endl;
    cout<<getFood(grid5)<<endl;

    return 0;
}