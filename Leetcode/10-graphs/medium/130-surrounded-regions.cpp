/*******************************************************************
Given a matrix, capture ('X') all regions that are surrounded ('O')

Distinguish captured vs escaped, 'X' vs 'O' vs 'E'

Time: O(m x n)
Space: O(m x n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ------- DOES NOT WORK FOR SOME CASES -------

// vector<int> dx = {0, 0, 1, -1};
// vector<int> dy = {-1, 1, 0, 0};

// bool in_bounds(int i, int j, vector<vector<char>>& board) {
//     return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
// }

// bool is_valid_region(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited) {
//     visited[i][j] = true;

//     bool is_valid = true;
//     for(int k=0; k<4; k++) {
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         if(!in_bounds(next_i, next_j, board)) return false;   
//         if(!visited[next_i][next_j] && board[next_i][next_j] == 'O') {
//             // if(!in_bounds(next_i, next_j, board)) return false;
//             bool validity = is_valid_region(next_i, next_j, board, visited);
//             if(!validity) 
//                 is_valid = is_valid && validity;
//         }
//     }

//     return is_valid;
// }

// void capture_valid_region(int i, int j, vector<vector<char>>& board, vector<vector<int>>& visited) {
    
//     if(!in_bounds(i, j, board)) return;
//     if(board[i][j] == 'X') return;

//     board[i][j] = 'X';
//     visited[i][j] = true;

//     for(int k=0; k<4; k++) {
//         int next_i = i + dx[k];
//         int next_j = j + dy[k];
//         capture_valid_region(next_i, next_j, board, visited);
//     }
    
// }

// void solve(vector<vector<char>>& board) {
//     int rows = board.size();
//     int cols = board[0].size();
//     vector<vector<int>> visited(rows, vector<int>(cols, 0));

//     vector<int> valid_i;
//     vector<int> valid_j;
//     int n = 0;

//     for(int i=0; i<rows; i++) {
//         for(int j=0; j<cols; j++) {
//             if(board[i][j] == 'O' && !visited[i][j]) {
//                 if(is_valid_region(i, j, board, visited)) {
//                     cout<<"\nFound a VALID region at: "<<i<<", "<<j;
//                     n++;
//                     valid_i.push_back(i);
//                     valid_j.push_back(j);
//                 } else {
//                     cout<<"\nFound INVALID region at: "<<i<<", "<<j;
//                 }
//             }
//         }
//     }

    
//     for(auto v : visited) fill(v.begin(), v.end(), 0);

//     for(int idx=0; idx<n; idx++) {
//         capture_valid_region(valid_i[idx], valid_j[idx], board, visited);
//     }

// }

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {-1, 1, 0, 0};

bool in_bounds(int i, int j, vector<vector<char>>& board) {
    return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
}

void dfs(int i, int j, vector<vector<char>>& board) {
    if(!in_bounds(i, j, board)) return;
    if(board[i][j] != 'O') return;

    // The cell is O
    board[i][j] = 'E';

    for(int k=0; k<4; k++) {
        int next_i = i + dx[k];
        int next_j = j + dy[k];
        dfs(next_i, next_j, board);
    }
}

void solve(vector<vector<char>>& board) {
    
    int rows = board.size();
    int cols = board[0].size();

    vector<pair<int,int>> borders;

    // top and bottom rows
    for(int j=0; j<cols; j++) {
        borders.push_back({0, j});
        borders.push_back({rows-1, j});
    }

    // first and last column
    for(int i=0; i<rows; i++) {
        borders.push_back({i, 0});
        borders.push_back({i, cols-1});
    }

    // run dfs on every border element
    for(auto border : borders) {
        int i =  border.first;
        int j = border.second;
        dfs(i, j, board);
    }

    // E => O
    // O => X
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            if(board[i][j] == 'E') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {


    vector<vector<char>> board = {
        {'O','O','O','X','O','O','O','O','X'},
        {'O','X','O','X','O','O','O','O','X'},
        {'O','X','O','O','O','O','O','O','O'},
        {'O','O','O','O','X','O','O','O','O'},
        {'X','O','O','O','O','O','O','O','X'},
        {'X','X','O','O','X','O','X','O','X'},
        {'O','O','O','X','O','O','O','O','O'},
        {'O','O','O','X','O','O','O','O','O'},
        {'O','O','O','O','O','X','X','O','O'}
    };

    solve(board);

    cout<<"\n\nBOARD\n";

    int rows = board.size();
    int cols = board[0].size();
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}